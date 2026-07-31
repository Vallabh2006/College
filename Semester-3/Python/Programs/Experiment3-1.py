def fib(n):

    a = 0
    b = 1

    for i in range(n):
        print(a, end=" ")

        a, b = b, a + b


n = int(input("\nEnter the number of terms: "))

print("\nFibonacci Series:")

fib(n)

print("\n")