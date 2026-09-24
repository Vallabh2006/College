n = int(input("\nEnter number of elements: "))

myList = []

for i in range(n):
    value = int(input("Enter element {}: ".format(i + 1)))
    myList.append(value)

print("\nOriginal List:", myList)

position = int(input("\nEnter position for insertion: "))
value = int(input("Enter value to insert: "))

myList.insert(position, value)

print("\nAfter Insertion:", myList)

position = int(input("\nEnter position for deletion: "))

if position < len(myList):
    myList.pop(position)
    print("\nAfter Deletion:", myList, "\n")
else:
    print("\nInvalid position.\n")