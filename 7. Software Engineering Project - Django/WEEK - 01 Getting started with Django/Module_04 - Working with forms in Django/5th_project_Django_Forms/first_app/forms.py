from django import forms
from django.core import validators

#widgets == field to HTML Tag


class contactForm(forms.Form):
    name = forms.CharField(label='User Name ', initial='Muktadir', 
            help_text='must be 10 character long', required=False, max_length=10, 
            disabled=False, widget=forms.Textarea(attrs={'id': 'text_area', 
            'class': 'class1 class2 clas3', 'placeholder': 'Enter your name...'}))
    file = forms.FileField()
    email = forms.EmailField(label='User Email')
    
    age = forms.IntegerField(label='User Age')
    age = forms.CharField(widget=forms.NumberInput)
    
    weight = forms.FloatField(label='User weight')
    balace = forms.DecimalField(label='User balance')
    check = forms.BooleanField()
    
    birthday = forms.DateField(widget=forms.DateInput(attrs={'type':'date'})) 
    appointment = forms.DateTimeField(widget=forms.DateInput(
                                        attrs={'type':'datetime-local'}))
    
    CHOICES = [('S', 'Small'), ('M', 'Medium'), ('L', 'Large')]
    size = forms.ChoiceField(choices=CHOICES, widget=forms.RadioSelect)
    
    INGRADIENT = [('P', 'Pepperoni'), ('C', 'Cheese'), ('M', 'Mushrooms')]
    pizza = forms.MultipleChoiceField(choices=INGRADIENT, 
                                        widget=forms.CheckboxSelectMultiple)
    

# class StudentData(forms.Form):
#     name = forms.CharField(widget=forms.TextInput)
#     email = forms.EmailField()
    
    # def clean_name(self):
    #     valuename = self.cleaned_data['name']
    #     if len(valuename) < 10:
    #         raise forms.ValidationError('Name must be 10 character long')
        
    #     return valuename
    
    # def clean_email(self):
    #     valueemail = self.cleaned_data['email']
    #     if '.com' not in valueemail:
    #         raise forms.ValidationError('Email must be contain .com')
        
    #     return valueemail
   
 #<<<---------,,,,,,,,,,Or Alternative,,,,,,,,,,--------------->>   
    
# class StudentData(forms.Form):
#     name = forms.CharField(widget=forms.TextInput)
#     email = forms.EmailField()  
    # def clean(self):
    #     self.cleaned_data = super().clean()  
    #     valname = self.cleaned_data['name']
    #     valemail = self.cleaned_data['email']
    #     if len(valname) < 10:
    #         raise forms.ValidationError('Name must be 10 character long')
    #     if '.com' not in valemail:
    #         raise forms.ValidationError('Email must be contain .com')


#<<<---------,,,,,,,,,,Built-in Validators,,,,,,,,,,--------------->>

class StudentData(forms.Form):
    name = forms.CharField(widget=forms.TextInput, 
                           validators=[validators.MaxLengthValidator(10, message='Name can not be more than 10 character long'),
                                       validators.MinLengthValidator(5, message='Name must be 5 character long')])
    email = forms.EmailField()
    age = forms.IntegerField(validators=[validators.MaxValueValidator(50, message='Age can not be more than 50'),
                                         validators.MinValueValidator(18, message='Age must be 18 or more')])
    
    # file = forms.FileField(validators=[validators.FileExtensionValidator(
    #     allowed_extensions=['pdf'], message='Only pdf file can be uploaded')])
    
#<<<---------,,,,,,,,,,Custom Validators,,,,,,,,,,--------------->>    

    def file_exe(value):
        if value not in ['pdf', 'docx', 'txt', 'xlsx', 'pptx']:
            raise forms.ValidationError('Name must be 10 character long')

    file = forms.FileField(validators=[file_exe])
    
    
class PasswordValidationProject(forms.Form):
    name = forms.CharField(widget=forms.TextInput)
    password = forms.CharField(widget=forms.PasswordInput)
    confirm_password = forms.CharField(widget=forms.PasswordInput)
    
    def clean(self):
        self.cleaned_data = super().clean()
        user_name = self.cleaned_data['name']
        val_pass = self.cleaned_data['password']
        con_pass = self.cleaned_data['confirm_password']
        
        if len(user_name) > 15:
            raise forms.ValidationError('Username must be 15 character long')
        
        if val_pass != con_pass:
            raise forms.ValidationError('Password does not match')
        
        
            