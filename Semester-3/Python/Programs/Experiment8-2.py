class Student:

    rollnumber = []
    marks = []

    def __init__(self, n):

        for i in range(int(n)):
            self.addInput(i)

    def addInput(self, i):
        self.rollnumber.append(i+101)
        self.marks.append(input("Enter Student "+str(i+1)+"'s marks: "))

    def displayMarks(self):

        key_value = zip(self.rollnumber, self.marks)

        print("|  Roll  | mark  |")

        for key, value in key_value:
            print("| ", key,"  | ", value, "  | ")

n = input("\nEnter Number of Students: ")
print("\n", end="")

student = Student(n)
print("")

student.displayMarks()
print("")