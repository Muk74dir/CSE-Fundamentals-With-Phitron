t = int(input())
num = list(map(int, input().split()))

idx = 0
while True:
    check = filter(lambda x : x%2==0, num)
    if(len(list(check)) == t):
        num = list(map(lambda y : y//2, num))
        idx += 1
    else:
        break

print(idx)