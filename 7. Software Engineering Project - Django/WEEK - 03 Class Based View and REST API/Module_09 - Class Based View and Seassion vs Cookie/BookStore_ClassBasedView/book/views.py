from django.http import HttpResponse
from django.shortcuts import render, redirect
from book.forms import BookStoreForm
from book.models import BookStoreModel
from django.views.generic import TemplateView, ListView, DetailView
from django.views.generic.edit import FormView, CreateView, UpdateView, DeleteView
from django.urls import reverse_lazy
from django.http import HttpResponse


# Function Based View
# def home(request):
#     return render(request, 'base.html')

# Class Based View
class MyTemplateView(TemplateView):
    template_name = 'home.html'
    def get_context_data(self, **kargs):
        context = super().get_context_data(**kargs)
        context = {'name': 'Muktadir', 'age': 23}
        context.update(kargs) # Updating Dictionary 
        print(kargs)
        print(context)
        return context


def store_book(request):
    if request.method == 'POST':
        book = BookStoreForm(request.POST)
        if book.is_valid():
           book.save()
           print(book.cleaned_data)
           return redirect('show_books')
    else:
        book = BookStoreForm()
    return render(request, 'store_book.html', {'form':book})

# <-- Function Based View --> 
# def show_books(request):
#     book = BookStoreModel.objects.all()
#     for i in book:
#         print(i.first_pub)
#     return render(request, 'show_books.html', {'data':book})


# Class Based List View --->
class BookListView(ListView):
    model = BookStoreModel
    template_name = 'show_books.html'
    context_object_name = 'data' # data from the specific model
    ordering = ['id']

    # Sorting Data : -- > 
    # def get_queryset(self):
    #     return BookStoreModel.objects.filter(category='Thriller')
    
    # Passing With External Context : --> 
    # def get_context_data(self, **kargs):
    #     context = super().get_context_data(**kargs)
    #     context = {'Rahim': BookStoreModel.objects.all().order_by('book_name')}
    #     return context

    # Overwrite Templte : --> 
    def get_template_names(self):
        if self.request.user.is_superuser:
            template_name = 'superuser.html'
        elif self.request.user.is_staff:
            template_name = ''
        else:
            template_name = self.template_name
        
        return [template_name]

# Class Based Detail View --->
class BooksDetailView(DetailView):
    model = BookStoreModel
    template_name = 'book_details.html'
    context_object_name = "item" # for accessing the data in template
    pk_url_kwarg = 'id'

#Class Based Form View --->
class BookFormView(FormView):
    template_name = 'store_book.html'
    form_class = BookStoreForm
    success_url = '/show_books/'
    success_url = reverse_lazy('show_books') # from url name

    def form_valid(self, form):
        print(form.cleaned_data)
        form.save() # One Way for save 
        return redirect('show_books')
        # return HttpResponse('<h1> Form Submitted </h1>')

# Class Based Create View --->
class BookFormView(CreateView):
    model = BookStoreModel
    template_name = 'store_book.html'
    form_class = BookStoreForm
    success_url = reverse_lazy('show_books') # AUTO SAVE + REDIRECT 


# Functional View : 
def edit_book(request, id):
    book = BookStoreModel.objects.get(pk=id)
    form = BookStoreForm(instance=book)
    if request.method == 'POST':
        form = BookStoreForm(request.POST, instance=book)
        if form.is_valid():
            form.save()
            return redirect('show_books')
    return render(request, 'store_book.html', {'form':form}) 

# Edit / Update View : 
class BookUpdateView(UpdateView):
    model = BookStoreModel
    template_name = 'store_book.html'
    form_class = BookStoreForm
    success_url = reverse_lazy('show_books')

# Delete View : 
class DeleteBookView(DeleteView):
    model = BookStoreModel
    template_name = 'delete_confirm.html'
    success_url = reverse_lazy('show_books')

# def delete_book(request, id):
#     book = BookStoreModel.objects.get(pk=id).delete()
#     return redirect('show_books')