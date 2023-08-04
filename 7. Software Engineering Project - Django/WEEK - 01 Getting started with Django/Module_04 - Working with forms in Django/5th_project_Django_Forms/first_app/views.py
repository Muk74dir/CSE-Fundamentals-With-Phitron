from django.shortcuts import render
from . forms import contactForm, StudentData, PasswordValidationProject

def home(request):
    return render(request, 'home.html')

def about(request):
    if request.method == 'POST':
        print(request.POST)
        name = request.POST.get('username')
        email = request.POST.get('email')  
        select = request.POST.get('select') 
        return render(request, 'about.html', { 'name': name, 'email': email , 'select': select })
    else:
        return render(request, 'about.html')

def submit_form(request):
    return render(request, 'form.html')

def DjangoForm(request):
    if request.method == 'POST':
        form = contactForm(request.POST, request.FILES)   
        if form.is_valid():
            file = form.cleaned_data['file']
            with open("first_app/upload/" + file.name, 'wb+') as destination :
                for chunk in file.chunks():
                    destination.write(chunk) 
            print(form.cleaned_data)
    else:
        form = contactForm()
        
    return render(request, 'django_form.html', {'form': form})

def StudentForm(request):
    if request.method == 'POST':
        form = StudentData(request.POST)  
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = StudentData() 
    return render(request, 'student_form.html', {'form': form})


def PasswordValidation(request):
    if request.method == 'POST':
        form = PasswordValidationProject(request.POST)  
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = PasswordValidationProject() 
    return render(request, 'password_validation.html', {'form': form})

