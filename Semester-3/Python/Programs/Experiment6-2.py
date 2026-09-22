import os

directory = os.path.join(os.path.dirname(__file__), "../Material/")
file_name = input("File Name: ")
extension = ".txt"

file_path = directory+file_name+extension

try:
    with open(file_path, 'r') as file:
        content = file.read()
        print("File Contents:")
        print(content)

except Exception as e:
    print(f"An error occurred: {e}")   