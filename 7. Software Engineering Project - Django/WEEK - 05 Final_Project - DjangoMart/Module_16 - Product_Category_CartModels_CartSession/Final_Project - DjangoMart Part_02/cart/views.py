from django.shortcuts import render, redirect
from store.models import ProductModel
from .models import CartModel, CartItemModel

def cart(request):
    return render(request, 'cart/cart.html')


def add_to_cart(request, product_id):
    product = ProductModel.objects.get(id=product_id)
    cart_session_id = request.session.session_key
    cart_id = CartModel.objects.filter(cart_id=cart_session_id).exists()

    if cart_id:
        cart_items = CartItemModel.objects.filter(product=product, cart=cart_id).exists()
        cart_id = CartModel.objects.get(cart_id=cart_session_id)

        if cart_items:
            cart_item = CartItemModel.objects.get(product=product, cart=cart_id)
            cart_item.quantity += 1
            cart_item.save()

        else:
            cart_item = CartItemModel.objects.create(
                product=product, 
                cart=cart_id, 
                quantity=1
            )
            print('part2')
            cart_item.save()
    else:
        cart_id = CartModel.objects.create(cart_id=cart_session_id)
        cart = CartItemModel.objects.create(
            cart=CartModel.objects.get(cart_id=cart_session_id),
            quantity=1
            )
        cart.save()
    return redirect('cart')