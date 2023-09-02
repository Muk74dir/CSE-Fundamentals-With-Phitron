from django.shortcuts import render, redirect
from store.models import ProductModel
from .models import CartModel, CartItemModel
from django.db.models import Q

def get_session_key(request):
    if request.session.session_key is None:
        request.session.create()
    return request.session.session_key


def cart(request):

    context = {}
    tax = 0
    total = 0
    grand_total = 0

    cart_session_id = get_session_key(request)
    cart_items = CartItemModel.objects.filter(cart__cart_id=cart_session_id)
    cart_id = CartModel.objects.filter(cart_id=cart_session_id).exists() # check if cart exists or not

    if cart_id:
        cart_items = CartItemModel.objects.filter(cart__cart_id=cart_session_id)
        if cart_items:
            for item in cart_items:
                total = (item.product.price * item.quantity) 
            tax = (2 * total) / 100
            grand_total = total + tax
            context['tax'] = tax
            context['total'] = total
            context['grand_total'] = grand_total
            context['cart_items'] = cart_items
        else:
            context['cart_items'] = None
    else:
        context['cart_items'] = None
    
    return render(request, 'cart/cart.html', context)

def add_to_cart(request, product_id):
    product = ProductModel.objects.get(id=product_id)
    cart_session_id = get_session_key(request)

    cart_id = CartModel.objects.filter(cart_id=cart_session_id).exists()
    if cart_id:
        cart_items = CartItemModel.objects.filter(product=product).exists()
        if cart_items:
            cart_item = CartItemModel.objects.get(product=product)
            cart_item.quantity += 1
            cart_item.save()
        else:
            cart_id = CartModel.objects.get(cart_id=cart_session_id)
            cart_item = CartItemModel.objects.create(
                product=product, 
                cart=cart_id, 
                quantity=1
            )
            cart_item.save()
    else:
        cart_id = CartModel.objects.create(cart_id=cart_session_id)
        cart_items = CartItemModel.objects.create(
            product=product, 
            cart=cart_id, 
            quantity=1
        )
        cart_items.save()
    return redirect('cart')

def remove_item_from_cart(request, product_id): # first of all got to CartItemModel, then get product id from ProductModel Using product__id
    product = ProductModel.objects.get(id=product_id) # for getting specific only one product / without this line, it will get MultipleObjectsReturned error
    cart_session_id = request.session.session_key
    cart = CartModel.objects.get(cart_id=cart_session_id)
    cart_item = CartItemModel.objects.get(cart=cart, product=product)
    if cart_item.quantity > 1:
        cart_item.quantity -= 1
        cart_item.save()
    else:
        cart_item.delete()
    return redirect('cart')

def remove_from_cart(request, product_id):
    product = ProductModel.objects.get(id=product_id)
    cart_session_id = request.session.session_key
    cart_id = CartModel.objects.get(cart_id=cart_session_id)
    cart_item = CartItemModel.objects.get(cart=cart_id, product=product)
    cart_item.delete()
    return redirect('cart')