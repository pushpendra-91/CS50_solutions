""" validates the credit card """
card_no = input("Number:")
copy_card_no = card_no
card_digit_compare = card_no
sum = 0
checksum2 = 0
checksum1 = 0
# Finds the length of credit card
length = len(card_no)
# Loop find the sum of digits starting with the number’s second-to-last digit
for i in range(length):
    card_no = (int(card_no) // 10)
    sum = ((int(card_no) % 10) * 2)
# Find length of sum
    len_sum = len(str(sum))
# Block sum-up the digits after multiplying them
    if(sum > 0):
        for i in range(len_sum):
            checksum1 = checksum1 + (sum % 10)
            sum = sum//10
    card_no = card_no//10
# Following block sum-up the remaining digits that were not multiplied by 2
for i in range(length):
    sum = (int(copy_card_no) % 10)
    copy_card_no = (int(copy_card_no)//10)
    checksum2 = checksum2 + (sum % 10)
    sum = sum//10
    copy_card_no = copy_card_no//10
checksum = checksum1+checksum2
# Validates the card
if checksum % 10 == 0:
    if length == 15 and card_digit_compare[0] == "3":
        if card_digit_compare[1] == "4" or card_digit_compare[1] == "7":
            print("AMEX")
    if length == 13 or length == 16:
        if card_digit_compare[0] == "4":
            print("VISA")
    if length == 16 and card_digit_compare[0] == "5":
        if card_digit_compare[1] == "1" or card_digit_compare[1] == "2" or card_digit_compare[1] == "3" or card_digit_compare[1] == "4" or card_digit_compare[1] == "5":
            print("MASTERCARD")
else:
    print("INVALID")
