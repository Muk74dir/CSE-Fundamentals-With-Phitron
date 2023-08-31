from django import forms
from .models import TransactionModel

class TransactionFrom(forms.ModelForm):
    class Meta:
        model = TransactionModel
        fields = ['amount', 'transaction_type']
    
    def __init__(self, *args, **kwargs):
        self.account = kwargs.pop('account')
        super().__init__(*args, **kwargs)
        self.fields['transaction_type'].disabled = True # Field is Disabled
        self.fields['transaction_type'].widget = forms.HiddenInput() # Field is Hidden

    def save(self, commit=True):
        self.instance.account = self.account
        self.instance.balance_after_transaction = self.account.balance
        return super().save()
    
class DepositForm(TransactionFrom): 
    def clean_amount(self): # Built-in method to clean the amount field
        min_deposit_amount = 100
        amount = self.cleaned_data.get('amount')

        if amount < min_deposit_amount:
            raise forms.ValidationError(f'You need to deposit at least {min_deposit_amount}')

        return amount
    
class WithdrawForm(TransactionFrom): 
    def clean_amount(self): # Built-in method to clean the amount field
        min_withdraw_amount = 500
        max_withdraw_amount = 20000
        balance = self.account.balance
        amount = self.cleaned_data.get('amount')

        if amount < min_withdraw_amount:
            raise forms.ValidationError(f'You need to withdraw at least {min_withdraw_amount}')

        if amount > max_withdraw_amount:
            raise forms.ValidationError(f'You can withdraw maximum {max_withdraw_amount}')

        if amount > balance:
            raise forms.ValidationError(f'You have {balance} TK. You do not have enough balance to withdraw {amount}')

        return amount
    
class LoanRequestForm(TransactionFrom):
    def clean_amount(self):
        amount = self.cleaned_data.get('amount')
        min_loan_amount = 10000     
        max_loan_amount = 1000000
        if amount < min_loan_amount:
            raise forms.ValidationError(f'You need to request at least {min_loan_amount}')
        if amount > max_loan_amount:
            raise forms.ValidationError(f'You can request maximum {max_loan_amount}')
        return amount