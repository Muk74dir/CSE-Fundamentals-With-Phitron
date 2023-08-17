from django.urls import path
from first_app import views

urlpatterns = [
    path('', views.home, name = 'homepage'),
    path('signup/', views.signup, name = 'signup'),
    path('login/', views.user_login, name = 'loginpage'),
    path('profile/', views.profile, name = 'profilepage'),
    path('logout/', views.user_logout, name = 'logoutpage'),
    path('profile/reset_password_with_old/', views.reset_pass_old, name = 'reset_with_old_pass_page'),
    path('profile/reset_password/', views.reset_pass, name = 'reset_without_old_pass_page'),
    path('profile/update/', views.update_userdata, name = 'update_userdata')
]   