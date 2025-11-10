n = int(input())

total = 0
i = 1
while total + i * (i+1 ) // 2 <=n:
    total = total + i * (i+1 ) // 2
    i = i + 1
print(i-1)

