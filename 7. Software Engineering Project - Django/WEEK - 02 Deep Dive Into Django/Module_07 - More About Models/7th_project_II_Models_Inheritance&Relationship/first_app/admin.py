from django.contrib import admin
from first_app.models import StudentModel, StudentInfoModel, TeacherInfoModel, EmployeeModel, ManagerModel, Friend, Me, Person, Passport, Post, Student, Teacher

# Register your models here.
# admin.site.register(StudentModel)

# 1. Abstract Base Class
# admin.site.register(StudentInfoModel)
# admin.site.register(TeacherInfoModel)
# admin.site.register(EmployeeModel)
# admin.site.register(ManagerModel)



# 2. Multi-table Inheritance
# @admin.register(EmployeeModel)
# class EmployeeModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'name', 'city', 'designation']

# @admin.register(ManagerModel)
# class ManagerModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'name', 'city', 'designation', 'take_interview', 'hiring']


# 3. Proxy Model
# @admin.register(Friend)
# class FriendModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'school', 'section', 'attendacne', 'homework']

# @admin.register(Me)
# class MeModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'school', 'section', 'attendacne', 'homework']


# One to One Relationship

# @admin.register(Person)
# class PersonModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'name', 'city', 'email']

# @admin.register(Passport)
# class PassportModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'user', 'pass_number', 'pages', 'validity']


# # One to Many or Many to One Relationship
# @admin.register(Post)
# class PostModelAdmin(admin.ModelAdmin):
#     list_display = ['id', 'user', 'post_cap', 'post_details', 'created_at']



# Many to Many Relationship
@admin.register(Student)
class StudentModelAdmin(admin.ModelAdmin):
    list_display = ['id', 'name', 'roll', 'class_name']

@admin.register(Teacher)
class TeacherModelAdmin(admin.ModelAdmin):
    list_display = ['id', 'name', 'subject', 'studentlist', 'mobile']
