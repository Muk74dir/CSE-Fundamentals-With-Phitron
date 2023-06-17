from Bank import Bank
from Admin import Admin
from User import User

def main():
    print("Main is running\n")

    brac_bank = Bank("BRAC BANK")
    ab_bank = Bank("AB BANK")

    admin_1 = Admin("Muktadir")
    admin_1.create_account(brac_bank, "muktadir@gmail.com", 1719324, "Rajshahi")
    brac_bank.account_details(admin_1)


    user_1 = User("Saiful")
    user_1.create_account(brac_bank, "saiful@yahoo.com", 1923452, "Dhaka")
    user_1.deposit(brac_bank, 500)
    brac_bank.account_details(user_1)



    user_2 = User("Rajoni")
    user_2.create_account(brac_bank, "rajoni@outlook.com", 15236542, "Dhaka")
    user_2.deposit(brac_bank, 1000)
    brac_bank.account_details(user_2)

    user_2.check_balance(brac_bank)
    user_2.withdraw(ab_bank, 50)
    user_2.withdraw(brac_bank, 50)

    admin_1.switch_loan_feature(brac_bank, False)
    user_1.take_loan(brac_bank, 10000)
    admin_1.switch_loan_feature(brac_bank, True)

    user_1.take_loan(brac_bank, 1000)
    user_1.check_balance(brac_bank)
    user_2.check_balance(brac_bank)

    brac_bank.account_details(user_2)
    brac_bank.account_details(user_1)


    admin_1.total_available_balance(brac_bank)
    admin_1.total_loan_amount(brac_bank)


    user_2.withdraw(brac_bank, 5000)
    user_2.transfer_balance(brac_bank, user_1, 200)
    user_1.withdraw(brac_bank, 500)

    admin_1.total_available_balance(brac_bank)
    admin_1.total_loan_amount(brac_bank)

    user_3 = User("Shakib")
    brac_bank.account_details(user_3)
    ab_bank.account_details(admin_1)
    ab_bank.account_details(user_2)
    admin_2 = Admin("Sherlock")
    brac_bank.account_details(admin_2)


    user_1.transaction_history(brac_bank)
    user_2.transaction_history(brac_bank)
    user_3.transaction_history(brac_bank)
    user_1.transaction_history(ab_bank)

if __name__ == "__main__":
    main()