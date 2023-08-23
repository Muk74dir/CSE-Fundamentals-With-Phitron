from django.shortcuts import render
from django.http import HttpResponse
from datetime import datetime, timedelta

# COOKIE ------> > > > > 
def home(request):
    response = render (request, 'home.html')
    response.set_cookie('name', 'Rahim')
    response.set_cookie('name', 'Muktadir', max_age=60*3) # 3 Min
    response.set_cookie('name', 'Muk74dir', expires=datetime.utcnow()+timedelta(days=7)) # 7 Days
    return response

def get_cookie(request):
    name_from_cookie = request.COOKIES.get('name', 'Guest') # Default Value Guest
    print(request.COOKIES)
    print(name_from_cookie)
    return render(request, 'get_cookie.html', {'name': name_from_cookie})

def delete_cookies(request):
    response = render(request, 'delete_cookie.html')
    response.delete_cookie('name')
    return response

# Session vs Cookie

def set_session(request):
    data = {
        'name' : 'Muktadir',
        'age' : 23, 
        'language' : 'Bangla'
    }
    print(request.session.get_session_cookie_age())
    print(request.session.get_expiry_date())
    request.session.update(data)
    return render(request, 'home.html')

def get_session(request):
    if 'name' in request.session: 
        name = request.session.get('name')
        age = request.session.get('age')
        request.session.modified = True
        return render(request, 'get_session.html', {'name' : name, 'age': age})
    
    else:
        return HttpResponse( """ 
                <h1> Your Session has been expired. Kindly Log in Again. </h1>
            """ )
def delete_session(request):
    # del request.session['name'] 
    # del request.session['age'] # Delete Specific key-value from a session ID
    request.session.flush() # Delete Whole session ID 
    return render(request, 'delete_session.html')