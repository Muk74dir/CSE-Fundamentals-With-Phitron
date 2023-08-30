from django.urls import include, path
from rest_framework import routers
from .views import ProductViewSet, ProductReviewViewSet

router = routers.DefaultRouter()
router.register('products', ProductViewSet, basename='products')
router.register('reviews', ProductReviewViewSet, basename='reviews')

urlpatterns = [
    path('', include(router.urls)),
    path('api_auth/', include('rest_framework.urls')),
]