from django.urls import path
from . import views
urlpatterns = [
    path('', views.home, name='home'),
    path('add_task/', views.add_task, name='add_task'),
    path('show_tasks/', views.show_tasks, name='show_tasks'),
    path('completed_tasks/', views.completed_tasks, name='completed_tasks'),
    path('edit_task/<int:id>', views.edit_task, name='edit_task'),
    path('delete_task/<int:id>', views.delete_task, name='delete_task'),
    path('complete/<int:id>', views.complete, name='complete'),
    path('reset/', views.reset, name='reset')
]
