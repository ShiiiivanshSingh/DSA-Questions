def solve():
    import sys
    myau=sys.stdin.readline
    t=int(myau())
    for _ in range(t):
        numero=int(myau())
        s=myau().strip()
        if numero%2==1:
            print(-1)
            continue
        open_count=s.count("(")
        close_count=numero-open_count
        if open_count!=close_count:
            print(-1)
            continue
        print("("*(numero//2)+")"*(numero//2))

if __name__=="__main__":
    solve()
