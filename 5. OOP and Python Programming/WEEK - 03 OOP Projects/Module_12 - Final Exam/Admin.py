from datetime import datetime as dt
from User import User

class Admin(User):
    def __init__(self, name):
        self.name = name
        self.loan = 0
        self.balance = 0
        self.type = "Admin"

    def create_account(self, bank, email, phone, address):
        return super().create_account(bank, email, phone, address)


    def total_available_balance(self, bank):
        if self.name in bank.admins:
            print(f"The {bank.name} has Total Amount {bank.get_balance} BDT")
        else:
            print(f"Admin not Authorized to get access of {bank.name}")
    
    def total_loan_amount(self, bank):
        if self.name in bank.admins:
            print(f"The {bank.name} has Total Loan Amount {bank.get_loan_balance} BDT")
        else:
            print(f"Admin not Authorized to get access of {bank.name}")
    
    def switch_loan_feature(self, bank, switch=True):
        if self.name in bank.admins:
            if switch == True:
                bank.is_loan_enabled = True
                print(f'Loan Feature is On by {self.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
                bank.activity_log[self.name].append(f'Loan Feature is On by {self.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
            else:
                bank.is_loan_enabled = False
                print(f'Loan Feature is Off by {self.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
                bank.activity_log[self.name].append(f'Loan Feature is Off by {self.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
        else:
            print(f"Admin not Authorized to get access of {bank.name}")
    