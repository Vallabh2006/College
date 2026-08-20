n = int(input("\nEnter number of Elements: "))
numbers = []

print()

for i in range(n):
    numbers.append(int(input("Enter the " + str(i+1) + " Element: ")))

print("\nList:", numbers)
print("Total Number of Elements:", len(numbers))
print("Maximum Value:", max(numbers))
print("Minimum Value:", min(numbers))
print("Sum of Elements:", sum(numbers), "\n")