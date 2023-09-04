from django import forms
from .models import OrderModel

class OrderModelForm(forms.ModelForm):
    class Meta:
        model = OrderModel
        fields = ['first_name', 'last_name', 'phone_no', 'email', 'address_1', 'address_2', 'city', 'state', 'country', 'order_note']
        