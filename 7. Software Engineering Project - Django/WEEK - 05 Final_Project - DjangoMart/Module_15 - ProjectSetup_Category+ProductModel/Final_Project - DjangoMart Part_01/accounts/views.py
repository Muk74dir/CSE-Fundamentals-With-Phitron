from django.shortcuts import render

def register(request):
    return render(request, 'accounts/register.html')

def profile(request):
    return render(request, 'accounts/dashboard.html')

def user_login(request):
    return render(request, 'accounts/signin.html')