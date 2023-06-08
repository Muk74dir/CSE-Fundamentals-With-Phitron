class Bank:
    def __init__(self, balance):
        self.balance = balance
        self.min_withdraw = 100
        self.max_withdraw = 100000

    def get_balance(self):
        return self.balance

    def deposit(self, amount):
        if amount > 0: 
            self.balance += amount
        
    def withdraw(self, amount):
        if amount<self.min_withdraw:
            print(f"You Can't withdraw below: {self.min_withdraw}")
        elif amount > self.max_withdraw:
            print(f"You Can't withdraw more than: {self.max_withdraw}")
        else:
            self.balance -= amount
            print(f"Here is your money: {amount}")
            print(f"Your Balance After Withdraw is : {self.get_balance()}")

brac = Bank(15000)
brac.withdraw(25)
brac.withdraw(10000000000)
brac.withdraw(1000)

dbbl = Bank(5000)
dbbl.deposit(2000)
dbbl.deposit(4000)
print(dbbl.get_balance())