n = int(input())
digits = list(map(int, input().split()))
new_digits = {}

for i in range(n):
    x = digits[i]
    if x not in new_digits:
        new_digits[x] = 1
    else:
        new_digits[x] += 1
        
sum = 0
for x, y in new_digits.items():
    if y >= x: 
        sum += x
    
print(n - sum)