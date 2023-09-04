from django.contrib import admin
from .models import PaymentModel, OrderModel, OrderedProductModel, PaymentGatewaySettingsModel

admin.site.register(PaymentModel)
admin.site.register(OrderModel)
admin.site.register(OrderedProductModel)
admin.site.register(PaymentGatewaySettingsModel)


