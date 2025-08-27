n  =int(input())
score = {}
for _ in range(n):
    meow = input()
    score[meow] = score.get(meow , 0) + 1
win = max(score, key  =score.get)
print(win)    
