stack = []

n = int(input("\nEnter number of Elements: "))

print()

for i in range(n):
    stack.append(int(input("Enter the " + str(i + 1) + " Element: ")))

print("\nStack:", stack)

print("\nPopped Element ", len(stack), ": ", stack.pop())
print("Stack after Pop:", stack)

stack.append(int(input("\nElement to Push: ")))
print("Stack after Push:", stack, "\n")
