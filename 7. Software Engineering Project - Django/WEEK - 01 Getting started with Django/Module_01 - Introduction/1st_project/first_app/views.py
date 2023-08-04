from django.shortcuts import render
from django.http import HttpResponse

def home(request):
    return HttpResponse("<h1>Hello World..!</h1>")

def about(request):
    return HttpResponse("<h1>This is about page</h1>")