class Student:
    name = None
    dob = None

    def __init__(self):
        self.name = input("Enter Name: ")
        self.dob = int(input("Enter Year of Birth: "))

    def display(self):
        print("Name:", self.name)
        print("Age:", 2026 - self.dob)

s = Student()
s.display()