from django import forms
from first_app.models import StudentModel

class StudentForm(forms.ModelForm):
    class Meta:
        model = StudentModel

        # fields = ['name', 'roll']
        # exclude = ['roll']
        fields = "__all__"
        labels = {
            'name': 'Student Name ',
            'roll': 'Student Roll ',
            'father_name' : "Father's Name "
        }

        widgets = {
            'name' : forms.TextInput()
        }

        help_texts  = {
            'name': 'write your full name'
        }
        error_messages = {
            'name' : {'required': "Your Name is Required"}
        }

