def call():
    print("Calling Unknown Number")
    return "Call Done"

class Phone:
    price= 45000
    color = 'Black'
    brand = 'Xiaomi'
    features = ['camera', 'speaker', "hammer"]

    def call(self):
        print("Calling Known Person")
    
    def send_sms(self, number, sms):
        text = f'Sending SMS to : {number} and message: {sms}'
        return text

my_phone = Phone()
print(my_phone.features)
my_phone.call()
result = my_phone.send_sms(27762, "I Hate You")
print(result)
