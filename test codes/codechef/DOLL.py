for _ in range(int (input())):
    s=0
    a,b=map(int,input().split())
    c=list(map(int,input().split()))
    for i in range(a):
        if(c[i]>b): s+=1
    print(s)