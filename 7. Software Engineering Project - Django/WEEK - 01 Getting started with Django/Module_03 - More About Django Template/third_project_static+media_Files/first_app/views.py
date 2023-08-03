from django.shortcuts import render

def contact(request):
    return render (request, './first_app/index.html', 
                   context={'Author' : 'Muktadir', 'age': 18, 'marks': 45})
    

def contact(request):
    return render(request, './first_app/index.html', {'courses' : [
        {
            'id': 1,
            'course': 'Python',
            'teacher': 'Muktadir'
        },
        {
            'id': 2,
            'course': 'Java',
            'teacher': 'Rahim'
        },
        {
            'id': 3,
            'course': 'C++',
            'teacher': 'Karim'
        }
        
        ]})

def contact(request):
    return render(request, './first_app/index.html', 
                {'name' : 'I am Muktadir', 'mark': 50, 'lst': [1, 2, 3, 4, 6], 
                'blog':  "A tiny VS Code extension made up of a few commands that generate and insert lorem ipsum text into a text file. To use the extension, open the command palette (F1 or cmd/ctrl+shift+p, type  and select to insert either a line or paragrap"})