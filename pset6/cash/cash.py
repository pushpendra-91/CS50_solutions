from cs50 import get_float
# checks for non-negative input
while True:
    dollars = get_float("Change Owed: ")
    if dollars > 0:
        break
# converting float to integrs
cents = round(dollars * 100)
# initilizing the variables
pennies = 0
nickels = 0
dimes = 0
quarters = 0
# checks for changes of amount
while True:
    if cents >= 25:
        quarters = int(cents/25)
        cents = cents % 25
    elif cents >= 10:
        dimes = int(cents/10)
        cents = cents % 10
    elif cents >= 5:
        nickels = int(cents/5)
        cents = cents % 5
    elif cents >= 1:
        pennies = int(cents/1)
        cents = cents % 1
    else:
        break
# sumsup total coins
coins = quarters+dimes+nickels+pennies
print(coins)