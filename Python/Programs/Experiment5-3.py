n = int(input("\nEnter number of key-value pairs: "))
myDict = {}

for i in range(n):

    key = input("Enter key {}: ".format(i + 1))
    value = input("Enter value {}: ".format(i + 1))

    myDict[key] = value

print("\nDictionary:", myDict)

key = input("\nEnter key to retrieve value: ")

if key in myDict:
    print("Value:", myDict[key])
else:
    print("Key not found.")

key = input("\nEnter key to delete: ")

if key in myDict:
    del myDict[key]
    print("\nAfter Deletion:", myDict, "\n")
else:
    print("Key not found.\n")