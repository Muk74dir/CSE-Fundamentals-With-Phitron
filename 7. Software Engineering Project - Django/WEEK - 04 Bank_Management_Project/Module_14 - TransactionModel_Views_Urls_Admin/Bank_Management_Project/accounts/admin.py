from django.contrib import admin
from .models import UserBankAccount, UserAddress

admin.site.register(UserBankAccount)
admin.site.register(UserAddress)


