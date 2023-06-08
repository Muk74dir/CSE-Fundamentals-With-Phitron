class Shop:
    cart = [] #Shared // Class Attribute

    def __init__(self, buyer):
        self.buyer = buyer
        
    
    def add_to_cart(self, item):
        self.cart.append(item)

mahejaben = Shop("Mahejaben")
mahejaben.add_to_cart('Shoes')
mahejaben.add_to_cart("Mobile")

print(mahejaben.cart)

nisho = Shop("Afran Nisho")
nisho.add_to_cart("Cap")
nisho.add_to_cart("Watch")

print(nisho.cart)