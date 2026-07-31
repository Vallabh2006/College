def is_prime(num):

    if num < 2:
        return False

    for i in range(2, num):
        if num % i == 0:
            return False

    return True


def prime_numbers(start, end):

    for num in range(start, end + 1):
        if is_prime(num):
            print(num, end=" ")


start = int(input("\nEnter the starting number: "))
end = int(input("Enter the ending number: "))

print("\nPrime numbers between", start, "and", end, "are:")

prime_numbers(start, end)

print("\n")