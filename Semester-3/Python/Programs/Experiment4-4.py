def factorial(num):

    if num == 0 or num == 1:
        return 1

    return num * factorial(num - 1)

num = int(input("\nEnter a number: "))

print("\nFactorial of", num, "is:", factorial(num), "\n")