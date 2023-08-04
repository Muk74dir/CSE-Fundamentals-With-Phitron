from django.shortcuts import render
from . import templates
def home(request):
    return render(request, 'base.html')