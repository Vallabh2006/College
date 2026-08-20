import random
import math

for i in range(5):
    number = random.randint(1, 100)
    square_root = math.sqrt(number)

    print("Number:", number)
    print("Square Root:", round(square_root, 2))
    print()