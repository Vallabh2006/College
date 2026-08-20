text1 = input("\nEnter first string: ")
text2 = input("Enter second string: ")

print("\nConcatenation:", text1 + text2)
print("Length of first string:", len(text1))

print("Uppercase:", text1.upper())
print("Lowercase:", text1.lower())

start = int(input("\nEnter starting index for substring: "))
end = int(input("Enter ending index for substring: "))

print("Substring:", text1[start:end])

print()