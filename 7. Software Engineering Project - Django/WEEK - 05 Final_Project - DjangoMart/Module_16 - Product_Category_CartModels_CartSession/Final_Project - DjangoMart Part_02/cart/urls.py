from django.urls import path
from . import views

urlpatterns = [
    path('', views.cart, name='cart'),
    path('<int:product_id>/', views.add_to_cart, name='add_cart'), 
]
