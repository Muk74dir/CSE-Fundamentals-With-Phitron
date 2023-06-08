inp = input()
sum = 0
s = ""
ans = []
for i in range(len(inp)):
    if inp[i] == "L":
        sum -= 1
        s += "L"
    else:
        sum += 1
        s += "R"
    if sum == 0:
        ans.append(s)
        s = ""

print(len(ans))
for i in ans:
    print(i)