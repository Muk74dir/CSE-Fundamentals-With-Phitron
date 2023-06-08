class Shop:
    shopping_mall = "Bashundhara"

    def __init__(self, buyer):
        self.buyer = buyer
        self.cart = [] #Not Shared // Instance Attribute

    def add_to_cart(self, item):
        self.cart.append(item)
        
mehjaben = Shop("Mahjaben")
mehjaben.add_to_cart("Shoe")
mehjaben.add_to_cart("Mobile")

print(mehjaben.cart)

nisho = Shop("Afran Nisho")
nisho.add_to_cart("Hat")
nisho.add_to_cart("Watch")

print(nisho.cart)

apurba = Shop("Apurba")
apurba.add_to_cart("Chiruni")
print(apurba.cart)