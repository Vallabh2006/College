def factorial(num):

    result = 1

    while num > 0:
        result = result * num
        num = num - 1

    return result


num = int(input("\nEnter a number: "))

print("Factorial of", num, "is:", factorial(num), "\n")