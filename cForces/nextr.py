n,k = map(int, input().split())
marks = list(map(int, input().split()))


meow = marks[k-1] #cutoff
sybau = 0
for uga in marks:
    if uga>= meow and uga > 0:
        sybau +=1
print(sybau)


