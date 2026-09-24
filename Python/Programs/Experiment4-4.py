factorial = lambda n: 1 if n <= 1 else n * factorial(n - 1)

num = int(input("Enter a number: "))

if num < 0:
    print("Factorial does not exist.")
else:
    print("Factorial =", factorial(num))