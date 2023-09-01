from django.contrib import admin
from .models import ProductModel

# admin.site.register(ProductModel)


# Customizing the Admin Interface
class ProductAdminModel(admin.ModelAdmin):
    list_display = ['product_name', 'category', 'price', 'stock', 'is_available', 'created_at', 'modified_date']
    prepopulated_fields = {'slug' : ('product_name',)} # Must be a tuple

# Register the custom model : 
admin.site.register(ProductModel, ProductAdminModel)