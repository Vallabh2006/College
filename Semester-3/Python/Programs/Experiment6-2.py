import os

directory = os.path.join(os.path.dirname(__file__), "../Material/")
file_name = "sample1"
extension = ".txt"

def writeToFile(file, data, mode=None):
    filePath = os.path.join(directory, file + extension)

    try:
        with open(filePath, "x"):
            pass
    except FileExistsError:
        pass

    if mode is not None:
        with open(filePath, mode) as tempFile:
            tempFile.write(data)


while True:

    print("\n1) Read")
    print("2) Write")
    print("3) Append")
    print("4) Exit")

    choice = input("Enter your choice: ")

    if choice == "1":

        filePath = os.path.join(directory, file_name + extension)

        try:
            with open(filePath, "x"):
                pass
        except FileExistsError:
            pass

        with open(filePath, "r") as openFile:
            print("\nFile Contents:")

            data = openFile.read()

            if data:
                print(data)
            else:
                print("No Content Found")

    elif choice == "2":

        data = input("\nEnter data to write: ")
        writeToFile(file_name, data, "w")
        print("\nData written successfully.")

    elif choice == "3":

        data = input("\nEnter data to append: ")
        writeToFile(file_name, data, "a")
        print("\nData appended successfully.")

    elif choice == "4":
        break

    else:
        print("\nInvalid choice.")

print("\n")