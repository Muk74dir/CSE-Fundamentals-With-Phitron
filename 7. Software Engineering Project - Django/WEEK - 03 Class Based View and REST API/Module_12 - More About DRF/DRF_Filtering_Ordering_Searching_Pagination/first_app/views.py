from django.shortcuts import render
from rest_framework import viewsets
from . import models, serializers
from rest_framework.permissions import IsAuthenticated, IsAuthenticatedOrReadOnly 
from .permissions import AdminOrReadOnly, ReviewerOrReadOnly
from . import paginations

# Django REST Framework --- Filtering, Searching, Ordering and Pagination
from django_filters.rest_framework import DjangoFilterBackend
from rest_framework import filters


class ProductViewSet(viewsets.ModelViewSet):
    # permission_classes = [IsAuthenticated] # Default permission class
    permission_classes = [AdminOrReadOnly] # Custom permission class
    queryset = models.Product.objects.all()
    serializer_class = serializers.ProductSerializer

    # Searching By Product Name and Description
    # filter_backends = [filters.SearchFilter] # SeachFilter is used for searching 
    # search_fields = ['name', 'description'] # Searching by query params with SearchFilter

    # Filtering By Price
    # filter_backends = [filters.OrderingFilter]
    # ordering_fields = ['price'] # Ordering with OrderingFilter by query params 

    # Pagination ::: 
    # pagination_class = paginations.ProductPagination
    # pagination_class = paginations.ProductLimitOffsetPagination
    pagination_class = paginations.ProductCursorPagination # Order / Filter Over-write kore 


    
        

class ProductReviewViewSet(viewsets.ModelViewSet):
    # permission_classes = [IsAuthenticatedOrReadOnly] # Default permission class
    permission_classes = [ReviewerOrReadOnly] # Custom permission class
    queryset = models.ProductReview.objects.all() # Default queryset
    serializer_class = serializers.ProductReviewSerializer
    
    # Filtering By Rating and Product
    # filter_backends = [DjangoFilterBackend]
    # filterset_fields = ['rating', 'product'] # Filtering by query params with DjangoFilterBackend

    # OrderingFilter By Rating
    filter_backends = [filters.OrderingFilter]
    filterset_fields = ['rating'] # Filtering with OrderingFilter


    # def get_queryset(self):                # Filtering and Searching by query params 
    #     queryset = models.ProductReview.objects.all() 
    #     username = self.request.query_params.get('username')
    #     if username is not None:
    #         queryset = queryset.filter(user__username__icontains=username) # __icontains makes it case insensitive 
    #     return queryset