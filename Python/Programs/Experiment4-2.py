def simple_interest(principal, rate, time):

    interest = (principal * rate * time) / 100

    return interest

principal = float(input("\nEnter the principal amount: "))
rate = float(input("Enter the rate of interest: "))
time = float(input("Enter the time in years: "))

interest = simple_interest(principal, rate, time)

print("\nSimple Interest:", interest, "\n")