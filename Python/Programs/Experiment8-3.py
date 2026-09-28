class Bank:
    def __init__(self):
        self.name = input("Enter name: ")
        self.balance = float(input("Enter amount: "))
        print("Account Created!\n")

    def deposit(self):
        amount = float(input("Enter amount to deposit: "))
        self.balance += amount

    def display(self):
        print("\nName:", self.name)
        print("Balance:", self.balance)

b = Bank()
b.deposit()
b.display()