try:
    num1 = int(input("\nEnter the number (?/y): "))
    num2 = int(input("Enter the second (" + str(num1) + "/?): "))

    result = num1 / num2

except ValueError:
    print("\nError: Please enter numbers only.")

except ZeroDivisionError:
    print("\nError: Cannot divide by zero.")

else:
    print("\nResult:", round(result, 2))

finally:
    print("\nProgram execution completed.\n")