from rest_framework import serializers
from .models import Product, ProductReview
from rest_framework.permissions import IsAuthenticated # IsAuthenticatedOrReadOnly 

class ProductSerializer(serializers.ModelSerializer):
    reviews = serializers.StringRelatedField(many=True)
    class Meta:
        model = Product
        fields = '__all__'
    
class ProductReviewSerializer(serializers.ModelSerializer):
    class Meta:
        model = ProductReview
        fields = '__all__'