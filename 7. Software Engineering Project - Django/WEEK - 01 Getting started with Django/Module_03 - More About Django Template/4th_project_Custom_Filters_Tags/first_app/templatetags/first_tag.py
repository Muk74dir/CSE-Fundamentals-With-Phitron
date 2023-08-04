from django import template
from django.template.loader import get_template


register = template.Library()
def my_template(value, arg):
    if arg == 'change':
        value = "Rahim"
        return value
    elif arg == 'title':
        return value.title()
    else:
        value = "Karim"
        return value

def show_courses():
    courses = [
        {
            'id': 1,
            'course':"C",
            'teacher':"Muktadir"
        },
        {
            'id': 2,
            'course':"C++",
            'teacher':"Rahim"
        },
        {
            'id': 3,
            'course':"JavaScript",
            'teacher':"Karim"
        }
    ]
    return {"courses": courses}

courses_template = get_template('first_app/courses.html')
 
register.inclusion_tag(courses_template)(show_courses) 
register.filter('changed_name', my_template)