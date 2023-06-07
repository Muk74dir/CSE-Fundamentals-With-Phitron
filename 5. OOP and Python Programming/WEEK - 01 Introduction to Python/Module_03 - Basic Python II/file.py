with open('Sample.txt', 'w') as file:
    file.write("I Love You, Python...!\n")


with open('Sample.txt', 'a') as file:
    file.write("I Love You, Python...!")

with open('Sample.txt', 'r') as file:
    text = file.read()
    print(text)