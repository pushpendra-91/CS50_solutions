from cs50 import get_int
# checks for non-numeric and in range input(1-8)
while True:
    height = get_int("height: ")
    if height in range(1, 9):
        break
# prints the pattern
for i in range(1, height+1):
    print(" "*(height-i), end="")
    print("#"*i, end="")
    print(" "*2, end="")
    print("#"*i)