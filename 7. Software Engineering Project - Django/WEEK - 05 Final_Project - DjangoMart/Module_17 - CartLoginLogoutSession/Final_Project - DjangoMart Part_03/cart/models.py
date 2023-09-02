from django.db import models
from store.models import ProductModel
from django.contrib.auth.models import User


class CartModel(models.Model):
    cart_id = models.CharField(max_length=250, blank=True)
    date_added = models.DateField(auto_now_add=True)

    def __str__(self):
        return self.cart_id

class CartItemModel(models.Model): # Actually its a product in cart, so CartItemModel is a single product in a cart
    user = models.ForeignKey(User, on_delete=models.CASCADE, null=True)
    product = models.ForeignKey(ProductModel, on_delete=models.CASCADE) # if product has no variation, then we can use OneToOneField
    cart = models.ForeignKey(CartModel, on_delete=models.CASCADE, null=True)
    quantity = models.IntegerField()
    is_active = models.BooleanField(default=True)

    def sub_total(self):
        return self.product.price * self.quantity

    def __str__(self):
        return self.product.product_name
    