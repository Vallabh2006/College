choice = input("\nChoose:\n\t1 for Celsius to Fahrenheit.\n\t2 for Fahrenheit to Celsius.\n\nSelect: ")

if choice == "1":

    userTemp= float(input("\nEnter temperature (C): "))
    result = (userTemp * 9/5) + 32
    print("Temperature (F):", round(result, 2), "\n")

elif choice == "2":
    userTemp= float(input("\nEnter temperature (F): "))
    result = (userTemp - 32) * 5/9
    print("Temperature (C):", round(result, 2), "\n")

else:
    print("\nInvalid choice\n")