import os

filePath = os.path.join(os.path.dirname(__file__), "../Material/") + "sample2.txt"

data = input("\nEnter data to write: ")

with open(filePath, "w") as file:
    file.write(data)

print("Data written successfully.\n")

data = input("Enter additional data to append: ")

with open(filePath, "a") as file:
    file.write(data)

print("\nData appended successfully.")

with open(filePath, "r") as file:
    print("\nFile Contents:")
    print(file.read())