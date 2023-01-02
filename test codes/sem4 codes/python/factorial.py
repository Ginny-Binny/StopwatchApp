def fact(num):
    return 1 if(num==1 or num==0) else num* fact(num-1)
int=6
print("Fact ",int,"is",fact(int))

