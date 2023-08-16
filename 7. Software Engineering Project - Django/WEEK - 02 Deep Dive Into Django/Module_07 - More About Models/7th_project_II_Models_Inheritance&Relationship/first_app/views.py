from django.shortcuts import render
from first_app.forms import StudentForm
from first_app.models import Teacher, Student

# Create your views here.
def home(request):
    if request.method == "POST":
        form = StudentForm(request.POST)
        if form.is_valid():
            form.save()
            print(form.cleaned_data)
    else:
        form = StudentForm()
    return render(request, "home.html", {'form': form})


def show(request):
    #teachers list for one student
    student = Student.objects.get(name='Foysal')
    # teachers = student.teachers_set.all()
    teachers = student.teachers.all()
    for teacher in teachers:
        print(f'{teacher.name} teaches {student.name} {teacher.subject} {teacher.mobile}')
    #students list for one teacher
    return render(request, "show_data.html")