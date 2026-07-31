n = int(input("\nEnter number of elements in tuple: "))
myTuple = ()
elements = []

for i in range(n):
    value = input("Enter element {}: ".format(i + 1))
    elements.append(value)

myTuple = tuple(elements)

print("\nTuple:", myTuple)

index = int(input("\nEnter index to access: "))

if index < len(myTuple):
    print("Element at index", index, "is:", myTuple[index])
else:
    print("Invalid index.")

print("\nTuple elements using loop:")

for i in range(len(myTuple)):
    print(myTuple[i], end=", " if i < len(myTuple) - 1 else "")

print("\n")