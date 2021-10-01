"""Program computes approximate grade level neede to comprehend some text"""
text = input("Text: ")
length = (len(text))
letters = 0
words = 0
sentences = 0
for i in range(length):
    # Counts no of letters in text
    if text[i].isalpha():
        letters += 1
    # Counts no of words-1 in text
    elif text[i] == " ":
        words += 1
    # Counts on of sentences in text
    elif text[i] == "." or text[i] == "!" or text[i] == "?":
        sentences += 1
L = round(((letters*100)/(words+1)), 2)
S = round(((sentences*100)/(words+1)), 2)
# Computes Grade Level according to Coleman-Liau index formula
index = round(0.0588 * L - 0.296 * S - 15.8)
# Block Prints the Grade Level according to index
if index < 1:
    print("Before Grade 1")
elif index > 1 and index < 16:
    print("Grade", index)
else:
    print("Grade 16+")