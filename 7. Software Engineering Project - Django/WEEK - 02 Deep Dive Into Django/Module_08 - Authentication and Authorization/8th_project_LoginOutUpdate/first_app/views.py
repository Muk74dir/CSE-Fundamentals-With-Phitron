from django.shortcuts import render, redirect
from django.contrib import messages
from first_app.forms import RegisterFrom, ChangeUserData
from django.contrib.auth.forms import AuthenticationForm, PasswordChangeForm, SetPasswordForm
from django.contrib.auth import authenticate, login, logout, update_session_auth_hash

def home(request):
    if request.method == 'POST':
        form = RegisterFrom(request.POST)
        if form.is_valid():
            messages.success(request, "Account created successfully")
            # messages.warning(request, "Account created successfully")
            # messages.info(request, "Account created successfully")
            form.save(commit=True)
            print(form.cleaned_data)
    else:
        form = RegisterFrom()

    return render(request, 'home.html', {'form': form})

def signup(request):
    if not request.user.is_authenticated:
        if request.method == 'POST':
            form = RegisterFrom(request.POST)
            if form.is_valid():
                messages.success(request, "Account created successfully")
                form.save()
                print(form.cleaned_data)
        else:
            form = RegisterFrom()
        return render(request, 'signup.html', {'form': form})
    else:
        return redirect('profilepage')

def user_login(request):
    if not request.user.is_authenticated:
        if request.method == 'POST':
            form = AuthenticationForm(request=request, data=request.POST)
            if form.is_valid():
                name = form.cleaned_data['username']
                user_pass = form.cleaned_data['password']
                user = authenticate(username=name, password=user_pass) # check if user exists in DB
                if user is not None:
                    login(request, user)
                    return redirect('profilepage')
        else:
            form =  AuthenticationForm()
        return render(request, 'login.html' , {'form': form})
    else:
        return redirect('profilepage')

def profile(request):
    if request.user.is_authenticated:
        return render(request, 'profile.html', {"user" : request.user})
    else:
        return redirect('loginpage')

def user_logout(request):
    logout(request)
    return redirect('loginpage')

def reset_pass_old(request):
    if request.user.is_authenticated:
        if request.method == "POST":
            form = PasswordChangeForm(user=request.user, data=request.POST)
            if form.is_valid():
                form.save()
                # update_session_auth_hash(request, form.cleaned_data['user'])
                update_session_auth_hash(request, form.user) # updates password in session without logging out 
                return redirect('profilepage')
        else:
            form = PasswordChangeForm(user=request.user)
        return render(request, 'reset_pass_old.html', {'form': form})
    else:
        return redirect('loginpage')

def reset_pass(request):
    if request.user.is_authenticated:
        if request.method == "POST":
            form = SetPasswordForm(user=request.user, data=request.POST)
            if form.is_valid():
                form.save()
                # update_session_auth_hash(request, form.cleaned_data['user'])
                update_session_auth_hash(request, form.user) # updates password in session without logging out 
                return redirect('profilepage')
        else:
            form = SetPasswordForm(user=request.user)
        return render(request, 'reset_pass.html', {'form': form})
    else:
        return redirect('loginpage')
    

def update_userdata(request):
    if request.user.is_authenticated:
        if request.method == 'POST':
            form = ChangeUserData(request.POST, instance=request.user)
            if form.is_valid():
                messages.success(request, "Account updated successfully")
                form.save()
        else:
            form = ChangeUserData(instance=request.user)
        return render(request, 'update.html', {'form': form})
    else:
        return redirect('loginpage')