from django.urls import path
# from book.views import home, store_book,show_books, edit_book, delete_book

# Shortcut View : 
from . import views

urlpatterns = [
    # Normal Functional View : 
    # path('', home, name="homepage"),

    # Shortcut View : 
    path('', views.TemplateView.as_view(template_name='home.html'), name='homepage'),

    # Class Based View : 
    path('<int:roll>/', views.MyTemplateView.as_view(template_name='home.html'), {'author': "Muktadir"}, name='homepage'),
    # List View
    path('show_books/', views.BookListView.as_view(), name='show_books'),
    # Detail View
    path('show_books/book_details/<int:id>', views.BooksDetailView.as_view(), name='book_details'),
    # Form View
    path('store_new_book/', views.BookFormView.as_view(), name='store_book'),
    # Update View 
    path('edit_book/<int:pk>', views.BookUpdateView.as_view(), name='edit_book'),

    # path('store_new_book/', views.store_book, name='store_book'),
    # path('edit_book/<int:pk>', views.edit_book, name='edit_book'),
    path('delete_book/<int:pk>', views.DeleteBookView.as_view(), name='delete_book'),
]
