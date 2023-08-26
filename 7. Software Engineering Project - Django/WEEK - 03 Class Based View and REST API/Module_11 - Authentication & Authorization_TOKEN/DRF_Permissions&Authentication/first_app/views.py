from django.shortcuts import render
from rest_framework import viewsets
from . import models, serializers
from rest_framework.permissions import IsAuthenticated, IsAuthenticatedOrReadOnly 
from .permissions import AdminOrReadOnly, ReviewerOrReadOnly

class ProductViewSet(viewsets.ModelViewSet):
    permission_classes = [AdminOrReadOnly]
    queryset = models.Product.objects.all()
    serializer_class = serializers.ProductSerializer

class ProductReviewViewSet(viewsets.ModelViewSet):
    permission_classes = [ReviewerOrReadOnly]
    queryset = models.ProductReview.objects.all()
    serializer_class = serializers.ProductReviewSerializer
