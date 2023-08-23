from django.urls import path
from . import views

urlpatterns = [
    # path("", views.home, name='homepage'),
    path("get_cookie/", views.get_cookie), # to Get cookie in another page
    path("delete_cookie/", views.delete_cookies), # to Delete cookie in another page

    path('set_session/', views.set_session), # set session 
    path('get_session/', views.get_session), # get session
    path('delete_session/', views.delete_session), # delete session
]  
