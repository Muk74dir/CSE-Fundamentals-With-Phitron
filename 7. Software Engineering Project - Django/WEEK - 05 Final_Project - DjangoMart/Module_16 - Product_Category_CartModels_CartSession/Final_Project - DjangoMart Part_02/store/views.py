from django.shortcuts import render, get_object_or_404 
from .models import ProductModel
from category.models import CategoryModel
from django.core.paginator import Paginator

def store(request, category_slug=None):

    if category_slug != None:
        category = get_object_or_404(CategoryModel, slug=category_slug)
        products = ProductModel.objects.filter(is_available=True, category=category)
        product_per_page = Paginator(products, 1)
        page_no = request.GET.get('page')
        paged_products = product_per_page.get_page(page_no)
    else:
        products = ProductModel.objects.all().filter(is_available=True)
        product_per_page = Paginator(products, 2)
        page_no = request.GET.get('page')
        paged_products = product_per_page.get_page(page_no)
        # for i in paged_products:
        #     print(i)

    # print(page_product.num_pages) # How many pages do we need?
    categories = CategoryModel.objects.all()
    context = {'products': paged_products, 'categories': categories}

    return render(request, 'store/store.html', context)

def product_detail(request, category_slug, product_slug):
    product = ProductModel.objects.get(category__slug=category_slug, slug=product_slug) # Or by related_name // We can also use get_object_or_404
    context = {'product': product} 
    return render(request, 'store/product-detail.html', context)
