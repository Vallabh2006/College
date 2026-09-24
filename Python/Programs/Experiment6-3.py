import os

directory = os.path.join(os.path.dirname(__file__), "../Material/")
file_name = input("File Name: ")
extension = ".txt"

file_path = directory+file_name+extension

data = input("\nEnter data to write: ")

with open(file_path, "w") as file:
    file.write(data)

print("Data written successfully.\n")

data = input("Enter additional data to append: ")

with open(file_path, "a") as file:
    file.write(data)

print("\nData appended successfully.")

with open(file_path, "r") as file:
    print("\nFile Contents:")
    print(file.read())