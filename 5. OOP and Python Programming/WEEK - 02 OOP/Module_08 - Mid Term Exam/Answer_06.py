n, m = list(map(int, input().split()))
num = list(map(int, input().split()))

ans = {}

for i in num:
    if i not in ans:
        ans[i] = 1
    else:
        ans[i] += 1

for j in range(1, m+1):
    if j in ans:
        print(ans[j])
    else:
        print(0)
