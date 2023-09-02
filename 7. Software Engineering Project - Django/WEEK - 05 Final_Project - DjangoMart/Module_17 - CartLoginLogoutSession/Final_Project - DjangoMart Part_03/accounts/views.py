from django.shortcuts import render, redirect
from .forms import RegistrationFrom
from django.contrib.auth import authenticate, login, logout
from cart.models import CartModel, CartItemModel

def get_session_key(request):
    if request.session.session_key is None:
        request.session.create()
    return request.session.session_key

def register(request):
    form = RegistrationFrom()
    if request.method == "POST":
        form = RegistrationFrom(request.POST)
        if form.is_valid():
            user = form.save()
            print(user)
            login(request, user)
            return redirect('profile') 
    return render(request, 'accounts/register.html', {'form': form})

def profile(request):
    return render(request, 'accounts/dashboard.html')

def user_login(request):
    if request.method == "POST": # if the form is submitted
        user_name = request.POST.get('username') # get the username from the form
        password = request.POST.get('password') # get the password from the form
        user = authenticate(username=user_name, password=password) # authenticate the user

        session_key = get_session_key(request)
        cart = CartModel.objects.filter(cart_id=session_key).exists()
        cart_items_exist = CartItemModel.objects.filter(cart=cart).exists()

        if user is not None:
            login(request, user)
            if cart_items_exist:
                cart_items = CartItemModel.objects.filter(cart=cart)
                for item in cart_items:
                    item.user = user
                    item.save()
            else:
                pass
            return redirect('profile')
    return render(request, 'accounts/signin.html')

def user_logout(request):
    sesssion_key = get_session_key(request)
    cart_id = CartModel.objects.filter(cart_id=sesssion_key).exists()
    if cart_id:
        cart = CartModel.objects.get(cart_id=sesssion_key)
        cart_items = CartItemModel.objects.filter(cart=cart)
        for item in cart_items:
            item.user = None
            item.save()
    logout(request)
    return redirect('login')