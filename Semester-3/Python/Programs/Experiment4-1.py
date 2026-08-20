def is_palindrome(num):

    num = str(num)

    if num == num[::-1]:
        return True

    return False

num = int(input("\nEnter a number: "))

if is_palindrome(num):
    print("\nThe number is a Palindrome.\n")
else:
    print("\nThe number is not a Palindrome.\n")