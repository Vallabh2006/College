import random

number = random.randint(1, 100)
attempts = 6

print("\nGuess the number between 1 and 100, You have", attempts, "attempts\n")

for i in range(attempts):

    guess = int(input("Enter your guess: "))

    if guess == number:
        print("\nCongratulations! You guessed the number.")
        break

    elif guess < number:
        print("Go up!", "\n")

    else:
        print("Go Down!", "\n")

else:
    print("\nYou lost!")
    print("The number was:", number)

print()