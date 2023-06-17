from datetime import datetime as dt
from Bank import Bank

class User:
    def __init__(self, name) -> None:
        self.name = name
        self.balance = 0
        self.loan = 0
        self.type = "User"

    def create_account(self, bank, email, phone, address):
        self.email = email
        self.phone = phone
        self.address = address

        if self.type == "User":
            print(f"######----User Account Created in {bank.name}---#####\n")
            bank.users[self.name] = self
        else:
            print(f"######----Admin Account Created in {bank.name}---#####\n")
            bank.admins[self.name] = self
        bank.activity_log[self.name] = [f'{self.type} : {self.name} Account Created at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}']

    def deposit(self, bank, amount):
        if self.name in bank.users:
            self.balance += amount
            bank.activity_log[self.name].append(f'{self.name} Credited BDT +{amount} in {bank.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
            bank.get_balance += amount
            print(f"Deposit Successful in {bank.name}. Amount : {amount} BDT")
        else:
            print(f"No Account found of {self.name} in {bank.name}")
        
    def withdraw(self, bank, amount):
        if self.name in bank.users:
            if  self.balance >= amount:
                if bank.get_balance >= amount:
                    self.balance -= amount
                    bank.get_balance -= amount
                    bank.activity_log[self.name].append(f'{self.name} Debited BDT -{amount} from {bank.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
                    print(f"Withdraw Successful. Amount : {amount} BDT")
                else:
                    print(f'\nSorry. The {bank.name} is bankrupt...!!!\n')
            else:
                print("Not Enough Money Available to Withdraw.")
        else:
            print(f"No Account found of {self.name} in {bank.name}")

    def check_balance(self, bank):
        if self.name in bank.users:
            print(f'User: {self.name} Balance : {self.balance} in {bank.name}')
        else:
            print(f"No Account Found for user : {self.name} in {bank.name}")
        

    def take_loan(self, bank, amount):
        if self.name in bank.users:
            if bank.is_loan_enabled == True:
                if bank.users[self.name].balance*2 >= (self.loan + amount):
                    self.loan += amount
                    bank.get_balance -= amount
                    bank.get_loan_balance += amount
                    print(f"User: {self.name} has got {amount} BDT Loan from {bank.name}")
                    bank.activity_log[self.name].append(f"{self.name} Took {amount} BDT Loan from {bank.name} at {dt.now().strftime('%Y-%m-%d %H:%M:%S')}")
                else:
                    print(f"User: {self.name} is not eligible to take loan now")
            else:
                print(f'Loan Facility is OFF in {bank.name}')
        else:
            print(f"No Account Found for user : {self.name} in {bank.name}")

    def transfer_balance(self, bank, to_user, amount):
        if (self.name in bank.users) and (to_user.name in bank.users):
            if self.balance >= amount:
                self.balance -= amount
                to_user.balance += amount
                bank.activity_log[self.name].append(f'{amount}BDT Transfered from {self.name} to {to_user.name} at {dt.now().strftime("%Y-%m-%d %H:%M:%S")}')
                print(f"Transfer Successful from {self.name} to {to_user.name} by {bank.name}")
            else:
                print("Not Enough Money Available to Transfer.")
        else:
            print("Transfer Failed")
            print('Reason : User has no account in this bank')


    def transaction_history(self, bank):
        if self.name in bank.users:
            print(f"\n####_____-Transaction_History-_____####")
            print(f"####_____-{bank.name}-_____####")
            print(f"####_____-{self.type}: {self.name} -_____####")
            for activity in bank.activity_log[self.name]:
                print(activity)
            print("\n")
        else:
            print(f'{self.type} Not Found in {bank.name}')

