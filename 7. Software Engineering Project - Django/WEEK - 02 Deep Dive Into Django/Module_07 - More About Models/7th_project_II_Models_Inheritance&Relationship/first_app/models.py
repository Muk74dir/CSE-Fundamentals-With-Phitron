from django.db import models

# Create your models here.

class StudentModel(models.Model):
    roll = models.IntegerField(primary_key=True)
    name = models.CharField(max_length=20)
    father_name = models.CharField(max_length=20)
    address = models.TextField()
    
    def __str__(self):
        return f"Name : {self.name}"
    

# Model Inheritance
# 1. Abstract Base Class
# 2. Multi-table Inheritance
# 3. Proxy Model


# 1. Abstract Base Class : 
class CommonInfoClass(models.Model):
    class Meta:
        abstract = True

    name = models.CharField(max_length=30)
    city = models.CharField(max_length=30) 

class StudentInfoModel(CommonInfoClass):
    roll = models.IntegerField()
    payment = models.IntegerField()
    section = models.CharField(max_length=30)

class TeacherInfoModel(CommonInfoClass):
    salary = models.IntegerField()


# 2. Multi-table Inheritance

class EmployeeModel(models.Model):
    name = models.CharField(max_length=30)
    city = models.CharField(max_length=30)
    designation = models.CharField(max_length=30)

class ManagerModel(EmployeeModel):
    take_interview = models.BooleanField()
    hiring = models.BooleanField()



# 3. Proxy Model

class Friend(models.Model): # Present in Class
    school = models.CharField(max_length=30)
    section = models.CharField(max_length=10)
    attendacne = models.BooleanField()
    homework = models.CharField(max_length=30)

class Me(Friend): # Absent in Class
    class Meta:
        proxy = True
        ordering = ['id']



# One to One Relationship

class Person(models.Model):
    name = models.CharField(max_length=30)
    city = models.CharField(max_length=30)
    email = models.EmailField(max_length=40)

    def __str__(self):
        return f"{self.name}"

class Passport(models.Model):
    user = models.OneToOneField(to=Person, on_delete=models.CASCADE) # One to One Relationship
    pass_number = models.IntegerField()
    pages = models.IntegerField()
    validity = models.IntegerField()

# One to Many or Many to One Relationship
class Post(models.Model):
    user = models.ForeignKey(Person, on_delete=models.SET_NULL, null=True) # One to Many Relationship
    post_cap = models.CharField(max_length=30)
    post_details = models.CharField(max_length=100)
    created_at = models.DateTimeField(auto_now_add=True)


# Many to Many Relationship
class Student(models.Model):
    name = models.CharField(max_length=30)
    roll = models.IntegerField()
    class_name = models.CharField(max_length=10)

    def __str__(self):
        return f"{self.name}"

 
class Teacher(models.Model): # Many to Many Relationship
    student = models.ManyToManyField(Student, related_name='teachers') 
    name = models.CharField(max_length=30)
    subject = models.CharField(max_length=30)
    mobile = models.CharField(max_length=11)

    def studentlist(self):
        return ", ".join([str(std) for std in self.student.all()])