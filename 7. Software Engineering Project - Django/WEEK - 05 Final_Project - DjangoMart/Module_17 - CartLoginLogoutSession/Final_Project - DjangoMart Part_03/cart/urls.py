from django.urls import path
from . import views

urlpatterns = [
    path('', views.cart, name='cart'),
    path('add/<int:product_id>/', views.add_to_cart, name='add_cart'),
    path('remove/<int:product_id>/', views.remove_item_from_cart, name='remove_item_from_cart'),
    path('delete/<int:product_id>/', views.remove_from_cart, name='remove_cart_item'),
]
