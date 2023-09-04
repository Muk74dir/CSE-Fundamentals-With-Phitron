from django.db import models
from django.contrib.auth.models import User
from store.models import ProductModel


class PaymentModel(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    payment_id = models.CharField(max_length=100)
    payment_method = models.CharField(max_length=100)
    amount_paid = models.DecimalField(max_digits=10, decimal_places=2)
    status = models.CharField(max_length=100)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.payment_id
    
class OrderModel(models.Model):
    STATUS =  (
        ('Ordered', 'Ordered'),
        ('Accepted', 'Accepted'),
        ('Completed', 'Completed'),
        ('Cancelled', 'Cancelled'),
    )
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    # payment = models.ForeignKey(PaymentModel, on_delete=models.CASCADE)
    order_number = models.CharField(max_length=100)
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    phone_no = models.CharField(max_length=100)
    email = models.EmailField(max_length=100)
    address_1 = models.CharField(max_length=100)
    address_2 = models.CharField(max_length=100)
    city = models.CharField(max_length=100)
    state = models.CharField(max_length=100)
    country = models.CharField(max_length=100)
    order_note = models.TextField()
    order_total = models.FloatField(max_length=100)
    tax = models.FloatField(max_length=100)
    status = models.CharField(max_length=100, choices=STATUS)
    ip = models.CharField(max_length=100, blank=True, null=True)
    is_ordered = models.BooleanField(default=False)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return self.order_number
    

class OrderedProductModel(models.Model):
    order = models.ForeignKey(OrderModel, on_delete=models.CASCADE)
    payment = models.ForeignKey(PaymentModel, on_delete=models.CASCADE)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    product = models.ForeignKey(ProductModel, on_delete=models.CASCADE)
    quantity = models.IntegerField()
    ordered = models.BooleanField(default=False)
    created_at = models.DateTimeField(auto_now_add=True)
    
    def __str__(self):
        return self.product
    

class PaymentGatewaySettingsModel(models.Model):
    store_id = models.CharField(max_length=100, blank=True, null=True)
    store_pass = models.CharField(max_length=100, blank=True, null=True)


    def __str__(self):
        return f"Store ID :--> {self.store_id}"
