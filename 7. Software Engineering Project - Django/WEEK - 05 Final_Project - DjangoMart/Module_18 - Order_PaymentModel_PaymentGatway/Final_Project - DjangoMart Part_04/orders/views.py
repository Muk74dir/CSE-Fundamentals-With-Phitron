from django.shortcuts import render, redirect
from cart.models import CartItemModel, CartModel
from store.models import ProductModel
from .models import OrderModel, OrderedProductModel, PaymentModel
from .forms import OrderModelForm
from django.contrib.auth.models import User

from django.views.decorators.csrf import csrf_exempt
from django.utils.decorators import method_decorator
from .ssl import sslcommerz_payment_gateway


def place_order(request):
    if request.user.is_authenticated:
        request.user = request.user
    else:
        return redirect('login')
    print(request.POST)
    context = {}
    tax = 0
    total = 0
    grand_total = 0
    cart_items = CartItemModel.objects.filter(user=request.user)
    
    if cart_items.count() < 1:
        return redirect('store')
    
    for item in cart_items:
        total += item.product.price * item.quantity
    tax = (2 * total) / 100
    grand_total = total + tax

    context['cart_items'] = cart_items
    context['tax'] = tax
    context['total'] = total
    context['grand_total'] = grand_total

    print(cart_items)
    
    if request.method == "POST":
        form = OrderModelForm(request.POST)
        if form.is_valid():
            form.instance.user = request.user
            form.instance.order_total = grand_total
            form.instance.tax = tax
            form.instance.ip = request.META.get('REMOTE_ADDR')
            saved_instance = form.save()

            form.instance.order_number = saved_instance.id
            
            form.save()
            print(form.cleaned_data)

            return redirect(sslcommerz_payment_gateway(request, saved_instance.id, str(request.user.id), grand_total))
        
    return render(request, 'orders/place_order.html', context)


@method_decorator(csrf_exempt, name='dispatch') # Disable CSRF
def success_view(request):
    data = request.POST
    print(data)

    usr_id = int(data['value_b'])
    user = User.objects.get(pk=usr_id)

    # Paymen Model Save
    payment = PaymentModel(
        user = user,
        payment_id = data['tran_id'],
        payment_method = data['card_type'],
        amount_paid = data['amount'],
        status = data['status']
    )

    payment.save()

    # Ordered Model Save
    order = OrderModel.objects.get(user=user, is_ordered=False, order_number=data['value_a'])
    order.payment = payment
    order.ordered = True

    order.save()



    # Ordered Product Model Save
    cart_items = CartItemModel.objects.filter(user=user)
    for item in cart_items:
        ordered_product = OrderedProductModel()
        product = ProductModel.objects.get(id=item.product.id)
        ordered_product.order = order
        ordered_product.payment = payment
        ordered_product.user = user
        ordered_product.product = product
        ordered_product.quantity = item.quantity
        ordered_product.ordered = True
        ordered_product.save()

        # Reduce the quantity of the sold products
        product.stock -= item.quantity
        product.save()

    # Clear Cart
    CartItemModel.objects.filter(user=user).delete() 
    
    return render(request, 'orders/order_complete.html')