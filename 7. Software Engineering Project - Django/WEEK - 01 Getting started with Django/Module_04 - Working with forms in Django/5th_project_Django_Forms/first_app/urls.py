from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('about/', views.about, name='about'),
    path('form/', views.submit_form, name='submit_form'),
    path('django_form/', views.DjangoForm, name='DjangoForm'),
    path('student_form/', views.StudentForm, name='StudentForm'), 
    path('password_validation/', views.PasswordValidation, name='Password'),
]