class BankAccount:
    def __init__(self, account_holder_name, account_number, initial_balance=0):
        self.account_holder_name = account_holder_name
        self.account_number = account_number
        self._balance = initial_balance 

    @property
    def balance(self):
        return self._balance

    @balance.setter
    def balance(self, value):
        if value >= 0:
            self._balance = value
        else:
            print("Invalid balance value. Balance must be non-negative.")

    def deposit(self, amount):
        if amount > 0:
            self._balance += amount
            print(f"{amount} deposited. New balance is: {self._balance}")
        else:
            print("Invalid amount. Deposit must be greater than 0.")

    def withdraw(self, amount):
        if 0 < amount <= self._balance:
            self._balance -= amount
            print(f"{amount} withdrawn. New balance is: {self._balance}")
        else:
            print("Insufficient funds or invalid withdrawal amount.")

    def display_balance(self):
        print(f"Current balance: {self._balance}")
        
    def __str__(self):
        return f"BankAccount({self.account_holder_name}, {self.account_number}, Balance: {self._balance})"          
account = BankAccount("John Doe", "123456789", 1000)
account.deposit(500)
account.withdraw(200)
account.display_balance()
account.withdraw(1500)
print(account)
