import os

filePath = os.path.join(os.path.dirname(__file__), "../Material/sample3.txt")

def saveContact():
    name = input("Enter Name: ")
    phone = input("Enter Phone Number: ")
    with open(filePath, "a") as f:
        f.write(f"{name},{phone}\n")

def showContact(phone=None):
    with open(filePath, "r") as f:
        for line in f:
            name, number = line.strip().split(",")
            if phone is None or number == phone:
                print("\nName:", name, "\nPhone:", number)
                if phone == number:
                    return
        if phone:
            print("Contact not found")

while True:
    print("\n1. Save Contact\n2. Show Contacts\n3. Find Contact\n4. Exit")
    choice = input("Enter your choice: ")

    if choice == "1":
        saveContact()
    elif choice == "2":
        showContact()
    elif choice == "3":
        showContact(input("Enter Phone Number to Search: "))
    elif choice == "4":
        break
    else:
        print("Invalid choice")