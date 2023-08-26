from rest_framework import permissions

class AdminOrReadOnly(permissions.IsAdminUser):
    def has_permission(self, request, view):
        if request.method in permissions.SAFE_METHODS: # GET Request
            return True
        
        else: # POST, PUT, PATCH, DELETE Request : 
            bool(request.user and request.user.is_staff)
        

class ReviewerOrReadOnly(permissions.BasePermission):
    def has_object_permission(self, request, view, obj):
        if request.method in permissions.SAFE_METHODS: # GET Request
            return True
        else: # POST, PUT, PATCH, DELETE Request :
            return obj.user == request.user