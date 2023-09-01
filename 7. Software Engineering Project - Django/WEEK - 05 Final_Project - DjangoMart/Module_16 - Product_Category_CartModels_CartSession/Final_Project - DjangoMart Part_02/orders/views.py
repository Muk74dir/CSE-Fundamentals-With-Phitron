from django.shortcuts import render

def order_complete(request):
    return render(request, 'orders/order_complete.html')