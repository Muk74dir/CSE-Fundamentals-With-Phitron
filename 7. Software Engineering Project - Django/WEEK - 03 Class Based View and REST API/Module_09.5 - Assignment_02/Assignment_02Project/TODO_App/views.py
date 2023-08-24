from django.shortcuts import render, redirect
from django.urls import reverse
from .models import TaskModel
from .forms import TaskForm
from datetime import datetime


def home(request):
    return render(request, 'base.html')

def add_task(request):
    if request.method == "POST":
        task = TaskForm(request.POST)
        if task.is_valid():
            task.save()
            return redirect('show_tasks')
    else:
        task = TaskForm()
    return render(request, 'add_task.html', {'form': task})

def show_tasks(request):
    tasks = TaskModel.objects.filter(is_completed=False)
    return render(request, 'show_tasks.html', {'tasks': tasks})


def completed_tasks(request):
    time = request.GET.get('time')
    tasks = TaskModel.objects.filter(is_completed=True)
    return render(request, 'completed_tasks.html', {'tasks': tasks, 'time': time})

def edit_task(request, id):
    task = TaskModel.objects.get(pk=id)
    task_form = TaskForm(instance=task)
    if request.method == "POST":
        task_form = TaskForm(request.POST, instance=task)
        if task_form.is_valid():
            task_form.save()
            return redirect('show_tasks')
    return render(request, '‘edit_task.html', {'form': task_form})

def delete_task(request,id):
    task = TaskModel.objects.get(pk=id)
    task.delete()
    return redirect('show_tasks')

def complete(request, id):
    task = TaskModel.objects.get(pk=id)
    complete_time = datetime.now().strftime("%d/%m/%Y %I:%M %p")
    task.is_completed = True
    task.save()
    url = reverse('completed_tasks') + f'?time={complete_time}'
    return redirect(url)

def reset(request):
    tasks = TaskModel.objects.all()
    for task in tasks:
        task.is_completed = False
        task.save()
    return redirect('show_tasks')