from django.shortcuts import render

def home(request):
    return render(request, 'first_app/home.html', {'name' : "I am Muktadir", 'marks': 23,
    "courses": [
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
    ]})

def about(request):
    return render(request, "./first_app/about.html", {'Author': "muktadir haque sarker"})