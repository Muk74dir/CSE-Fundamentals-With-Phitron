from typing import Any
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django import forms
from .models import UserBankAccount, UserAddress
from .constants import GENDER_TYPE, ACCOUNT_TYPE

class UserRegistrationFrom(UserCreationForm):
    birth_date = forms.DateField(widget=forms.DateInput(attrs={'type': 'date'})) # Showing calendar 
    gender = forms.ChoiceField(choices=GENDER_TYPE)
    account_type = forms.ChoiceField(choices=ACCOUNT_TYPE)
    street_address = forms.CharField(max_length=100)
    city = forms.CharField(max_length=50)
    postal_code = forms.IntegerField()
    country = forms.CharField(max_length=50)

    class Meta:
        model = User
        fields = ['username', 'password1', 'password2', 'first_name', 'last_name', 'email', 'account_type', 'birth_date', 'gender', 'street_address', 'postal_code', 'city', 'country']
    
    def save(self, commit=True):
        temp_user = super().save(commit=False) # Database e Save hobe na 
        if commit == True:
            temp_user.save() # user model er data save
            account_type = self.cleaned_data.get('account_type')
            gender = self.cleaned_data.get('gender')
            birth_date = self.cleaned_data('birth_date')
            street_address = self.changed_data('street_address')
            postal_code = self.cleaned_data.get('postal_code')
            city = self.cleaned_data.get('city')
            country = self.cleaned_data.get('country')

            UserAddress.objects.create (
                user = temp_user,
                street_address = street_address,
                postal_code = postal_code,
                city = city,
                country = country
            )

            UserBankAccount.objects.create(
                user = temp_user,
                account_type = account_type,
                gender = gender, 
                birth_date = birth_date,
                account_no = 100000 + temp_user.id
            )

        return temp_user
    

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        for field in self.fields:
            self.fields[field].widget.attrs.update({
                'class' : (
                    'appearance-none block w-full bg-gray-200 '
                    'text-gray-700 border border-gray-200 rounded '
                    'py-3 px-4 leading-tight focus:outline-none '
                    'focus:bg-white focus:border-gray-500 '
                )
            })

class UserUpdateForm(forms.ModelForm):
    account_type = forms.ChoiceField(choices=ACCOUNT_TYPE)
    gender = forms.ChoiceField(choices=GENDER_TYPE)
    birth_date = forms.DateField(widget=forms.DateInput(attrs={'type': 'date'}))
    street_address = forms.CharField(max_length=100)
    city = forms.CharField(max_length=50)
    postal_code = forms.IntegerField()
    country = forms.CharField(max_length=50)

    class Meta:
        model = User
        fields = ['first_name', 'last_name', 'email']

    def __init__(self, *args, **kargs):
        super().__init__(*args, **kargs)
        for field in self.fields:
            self.fields[field].widget.attrs.update({
                'class' : (
                    'appearance-none block w-full bg-gray-200 '
                    'text-gray-700 border border-gray-200 rounded '
                    'py-3 px-4 leading-tight focus:outline-none '
                    'focus:bg-white focus:border-gray-500 '
                )
            })
            
        if self.instance:
            try:
                user_account = self.instance.account
                user_address = self.instance.address
            except UserBankAccount.DoesNotExist:
                user_account = None
                user_address = None

            if user_account:
                self.fields['account_type'].initial = user_account.account_type
                self.fields['gender'].initial = user_account.gender
                self.fields['birth_date'].initial = user_account.birth_date
                self.fields['street_address'].initial = user_address.street_address
                self.fields['city'].initial = user_address.city
                self.fields['postal_code'].initial = user_address.postal_code
                self.fields['country'].initial = user_address.country

    def save(self, commit=False):
        user = super().save(commit=False)
        if commit:
            user.save()

            user.account, created = UserBankAccount.objects.get_or_create(user=user) # if account exists then get if not then create
            user.address, created = UserBankAccount.objects.get_or_create(user=user) # if account exists then get if not then create

            user.account.account_type = self.cleaned_data.get('account_type')
            user.account.gender = self.changed_data.get('gender')
            user.account.birth_date = self.cleaned_data.get('birth_date')
            user.account.save()

            
            user.account.street_address = self.changed_data.get('street_address')
            user.address.city = self.changed_data.get('city')
            user.address.postal_code = self.changed_data.get('postal_code')
            user.address.country = self.changed_data.get('country')
            user.address.save()

        return user
    


