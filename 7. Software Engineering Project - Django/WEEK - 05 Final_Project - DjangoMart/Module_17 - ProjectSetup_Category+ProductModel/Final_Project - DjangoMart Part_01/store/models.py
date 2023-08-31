from django.db import models
from category.models import CategoryModel

class ProductModel(models.Model):
    category = models.ForeignKey(CategoryModel, on_delete=models.CASCADE) # One to Many Relationship
    product_name = models.CharField(max_length=150, unique=True)
    slug = models.SlugField(max_length=150, unique=True)
    description = models.TextField(max_length=500, blank=True)
    price = models.IntegerField()
    image = models.ImageField(upload_to='photos/products', blank=True)
    stock = models.IntegerField()
    is_available = models.BooleanField(default=True)
    created_at = models.DateTimeField(auto_now_add=True) # Automatically set the field to now when the object is first created.
    modified_date = models.DateTimeField(auto_now=True) # Automatically set the field to now every time the object is Updated.

    def __str__(self):
        return self.product_name
