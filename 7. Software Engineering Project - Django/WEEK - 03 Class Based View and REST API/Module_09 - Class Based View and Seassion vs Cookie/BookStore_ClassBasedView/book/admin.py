from django.contrib import admin
from book.models import BookStoreModel
# Register your models here.


class BookStoreModelAdmin(admin.ModelAdmin):
    list_display = ('id', 'book_name', 'author', 'category', 'first_pub', 'last_pub')


admin.site.register(BookStoreModel, BookStoreModelAdmin)
