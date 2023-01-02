def fact(i):
    n=1
    while i>=1:
        n=i*n
        i=i-1
    return n
fac=fact(100)
print(fac)