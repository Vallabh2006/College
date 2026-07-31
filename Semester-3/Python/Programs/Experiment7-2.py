try:
    num1 = int(input("\nEnter the First Number (?/y): "))
    num2 = int(input("Enter the Second Number (" + str(num1) + "/?): "))

    result = num1 / num2

    print("\nResult:", round(result, 2), "\n")

except ValueError:
    print("\nError: Invalid input, Ener Integer..\n")

except ZeroDivisionError:
    print("\nError: Cannot divide by Zero.\n")