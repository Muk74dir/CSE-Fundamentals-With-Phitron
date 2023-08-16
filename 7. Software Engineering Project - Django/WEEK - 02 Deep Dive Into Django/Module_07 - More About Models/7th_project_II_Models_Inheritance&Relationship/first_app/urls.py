from django.urls import path
from . import views
from .views import home, show

#OR,
from first_app.views import home

urlpatterns = [
    path("", views.home, name="homepage"),
    path("", home, name="homepage"),
    path("show/", show, name="showpage"),
]
