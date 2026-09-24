import os

directory = os.path.join(os.path.dirname(__file__), "../Material/")
file_name = "sample3"
extension = ".txt"

filePath = os.path.join(directory, file_name + extension)

def findContact():

    print("\n--- Find Contacts ---")

    phone = input("\nEnter Phone Number to Search: ")

    with open(filePath, "r") as file:

        for line in file:
            name, number, email = line.strip().split(",")

            if number == phone:
                print("\nContact Found:")
                print("Name:", name)
                print("Phone:", number)
                print("Email:", email)
                return

    print("\nContact not found")

def saveContact():

    print("\n--- New Contact ---")

    contacts = []
    n = int(input("\nEnter number of Contacts: "))

    print()

    for i in range(n):

        print("Contact", i + 1)

        name = input("Enter Name: ")
        phone = input("Enter Phone Number: ")
        email = input("Enter Email: ")

        contacts.append([name, phone, email])

        print("")

    with open(filePath, "a") as file:

        for contact in contacts:
            file.write(
                contact[0] + "," +
                contact[1] + "," +
                contact[2] + "\n"
            )

    print("Contacts saved successfully.")

def showContact():

    print("\n--- Saved Contacts ---")

    with open(filePath, "r") as file:

        data = file.read()

        if data:
            for line in data.splitlines():
                name, phone, email = line.split(",")

                print("\nName:", name)
                print("Phone:", phone)
                print("Email:", email)
        else:
            print("No Contacts Found")

while True:

    print("\n1) Save Contacts")
    print("2) Show Contacts")
    print("3) Find Contact")
    print("4) Exit")

    choice = input("\nEnter your choice: ")

    if choice == "1":
        saveContact()

    elif choice == "2":
        showContact()

    elif choice == "3":
        findContact()

    elif choice == "4":
        break

    else:
        print("\nInvalid choice")

print()