t=int(input())
while(t):
    t=t-1
for i in range(t):
    n=int(input())
    l=[]
    for j in range(1,100000):
        if j%2!=0:
            n=n-1
            l.append(j)
            if n<=0:
                break 
          
    print(*1)
      