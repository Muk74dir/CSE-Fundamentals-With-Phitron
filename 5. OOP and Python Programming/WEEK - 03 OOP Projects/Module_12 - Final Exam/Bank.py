from datetime import datetime as dt

class Bank:
    def __init__(self, name) -> None:
        self.name = name
        self.__balance = 0
        self.__loan_ammount = 0
        self.__loan_switch = True
        self.users = {}
        self.admins = {}
        self.activity_log = {}


        print(f"##########---------->WELCOME TO {self.name}<---------#######\n\n\n")


    @property
    def get_balance(self):
        return self.__balance
    
    @get_balance.setter
    def get_balance(self, amount):
        self.__balance = amount
    

    @property
    def get_loan_balance(self):
        return self.__loan_ammount
    
    @get_loan_balance.setter
    def get_loan_balance(self, amount):
        self.__loan_ammount = amount


    @property
    def is_loan_enabled(self):
        return self.__loan_switch

    @is_loan_enabled.setter
    def is_loan_enabled(self, switch):
        self.__loan_switch = switch

    def account_details(self, user):
        if user.name in self.users or user.name in self.admins:
            print("\n<----------Account Details-------->")
            print(f'Account Name : {user.name}')
            print(f'Account Type : {user.type}')
            print(f'Bank Name : {self.name}')
            print(f'{user.type} Phone Number : {user.phone}')
            print(f'{user.type} Email : {user.email}')
            print(f'{user.type} Address : {user.address}')
            print(f'{user.type} Balance : {user.balance}')
            print(f'{user.type} Loan Amount {user.loan}\n\n')
        else:
            if user.type != "Admin":
                print(f'No Account found for user : {user.name} in {self.name}')
            else:
                print(f'No Admin Found named {user.name} in {self.name}')

        




