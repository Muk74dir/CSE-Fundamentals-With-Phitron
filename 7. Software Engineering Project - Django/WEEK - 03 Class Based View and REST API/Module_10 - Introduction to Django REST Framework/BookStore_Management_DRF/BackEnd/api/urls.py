from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

# Create a router and register our viewsets with it. [ Method 2 doesn't need this router ]
router = DefaultRouter()
router.register(r'books', views.BookViewSet, basename="book") # For Method 3

# The API URLs are now determined automatically by the router.
urlpatterns = [
    # Method 1 : 
    # path('books/', views.BookListView.as_view()), # Handles GET , POST REQUEST
    # path('books/<int:pk>/', views.BookListUpdateDelete.as_view()), # Handles GET , PUT / UPDATE , DELETE REQUEST

    # Method 2 :
    # path('books/', views.BookListListCreateAPIView.as_view()), # Handles GET , POST REQUEST
    # path('books/<int:pk>/', views.BookRetrieveUpdateDestroyAPIView.as_view()), # Handles GET , PUT / UPDATE , DELETE REQUEST

    # Method 3 :
    path('', include(router.urls)),

]