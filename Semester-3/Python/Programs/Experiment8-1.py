class Student:

    rollnumber = [101, 102, 103, 104]
    marks = [56, 29, 78, 35, 50]

    def displayRollnumber(self):
        return self.rollnumber

    def displayMarks(self):
        return self.marks

student = Student()

id = zip(student.displayRollnumber(), student.displayMarks())

print("|  Roll  | mark  |")

for roll, mark in id:
    print("| ", roll,"  | ", mark, "  | ")