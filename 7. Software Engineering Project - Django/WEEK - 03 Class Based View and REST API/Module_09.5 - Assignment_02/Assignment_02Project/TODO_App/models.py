from django.db import models

class TaskModel(models.Model):
    taskTitle = models.CharField(max_length=30)
    taskDescription = models.CharField(max_length=50)
    is_completed = models.BooleanField(default=False)
