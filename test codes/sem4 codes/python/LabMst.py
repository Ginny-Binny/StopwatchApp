#NAME: Gaurang Sharma
#UID: 20BCS4133

def fibb():
    l=[]
    f=0
    s=1
    t=1
    l.append(f)
    l.append(s)
    for i in range(0,8):
        t=f+s
        f=s
        s=t
        l.append(t)
    for j in range(1,len(l)):
        print("$"*l[j],l[j])
fibb()

def sumDigit():
    n=int(input("enter the number: "))
    s=str(n)
    sum=0
    for i in range(0,len(s)):
        sum=sum+int(s[i])
    print(sum)
sumDigit()