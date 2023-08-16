from django.db import models

# Create your models here.

class BookStoreModel(models.Model): 
    CATALOG = (
        ('Mystery', 'Mystery'),
        ('Thriller', 'Thriller'),
        ('Horror', 'Horror'),
        ('Sci-Fi', 'Sci-Fi'),
    )
    id = models.IntegerField(primary_key=True)
    book_name = models.CharField(max_length=30)
    author = models.CharField(max_length=30)
    category = models.CharField(max_length=30, choices=CATALOG)
    first_pub = models.DateTimeField(auto_now_add=True)
    last_pub = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f" ID : {self.id}"
