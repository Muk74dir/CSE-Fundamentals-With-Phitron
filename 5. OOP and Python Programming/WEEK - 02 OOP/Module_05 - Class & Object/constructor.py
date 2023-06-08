class Phone:
    manufactured = 'California, USA'

    def __init__(self, owner, brand, price):
        self.owner = owner
        self.brand = brand
        self.price = price

    def send_sms(self, num, sms):
        text = f'Sending to : {num} Message: {sms}'
        print(text)

my_phone = Phone("Muktadir", "POCO", 45000)
print(my_phone.owner, my_phone.brand, my_phone.price)

dad_phone = Phone("Abbu", "Nokia", 10000)
print(dad_phone.owner, dad_phone.brand, dad_phone.price)

her_phone = Phone("She", "Iphone", 99999)
print(her_phone.owner, her_phone.brand, her_phone.price)

my_phone.send_sms(8128, "Hi")
dad_phone.send_sms(23324, "Hello")
her_phone.send_sms(232334, "what's Up?")

