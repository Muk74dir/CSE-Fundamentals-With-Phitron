from django.shortcuts import render


def product_detail(request):
    return render(request, 'store/product-detail.html')

def store(request):
    return render(request, 'store/store.html')