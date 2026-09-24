marks = float(input("\nEnter the student's marks: "))

grades = ["A", "B", "C", "D", "F"]
ranges = [90, 80, 70, 60, 0]

for i in range(len(grades)):

    if marks >= ranges[i]:
        grade = grades[i]
        break

print("The student's grade is:", grade, "\n")