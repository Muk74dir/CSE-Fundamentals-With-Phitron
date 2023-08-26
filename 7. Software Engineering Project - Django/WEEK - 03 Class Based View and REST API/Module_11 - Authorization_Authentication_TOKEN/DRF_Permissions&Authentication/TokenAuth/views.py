from rest_framework import serializers, status
from rest_framework.response import Response
from rest_framework.views import APIView
from .serializers import RegistrationSerializer
from rest_framework.authtoken.models import Token
from . import signals

class RegistraionView(APIView):
    def post(self, request):
        data = {}
        serializers = RegistrationSerializer(data=request.data)
        if serializers.is_valid():
            account = serializers.save()
            data['response'] = 'Registration Successful'
            data['username'] = account.username
            data['email'] = account.email
            token = Token.objects.get(user=account).key
            data['token'] = token
        else:
            data = serializers.errors
        return Response(data)
    # return Response(data, status=status.HTTP_400_BAD_REQUEST)
    
class LogoutView(APIView):
    def post(self, request):
        request.user.auth_token.delete()
        return Response(status=status.HTTP_200_OK)