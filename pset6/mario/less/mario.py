from cs50 import get_int
# check for input in given range(1-8)
while True:
    height = get_int("Height: ")
    if height in range(1, 9):
        break
# prints pyramid
for i in range(1, height+1):
    print(" "*(height-i), end="")
    print("#"*i)