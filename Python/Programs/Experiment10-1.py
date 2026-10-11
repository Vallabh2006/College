stack = [4, 3, 5, 6]

def push():
    stack.append(int(input("Enter Element to Push: ")))
    display()

def pop():
    if stack:
        print("Popped Element:", stack.pop())
    display()

def display():
    print("Stack:", stack)

display()
push()
pop()