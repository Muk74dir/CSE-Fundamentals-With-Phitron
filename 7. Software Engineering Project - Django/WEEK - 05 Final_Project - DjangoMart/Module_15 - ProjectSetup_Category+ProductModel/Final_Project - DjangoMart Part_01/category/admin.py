from django.contrib import admin
from .models import CategoryModel

# admin.site.register(CategoryModel)

# Customizing the Admin Interface
class CategoryAdminModel(admin.ModelAdmin):
    prepopulated_fields = {'slug' : ('category_name',)} # Must be a tuple
    list_display = ('category_name', 'slug')

# Register your models here.
admin.site.register(CategoryModel, CategoryAdminModel)