# cook your dish here
testcase=int(input())
for i in range(testcase):
    s=input()
    s=''.join(sorted(s))
    sum=0
    for j in range(len(s)):
        sum=sum+(j+1)*(ord(s[j])-96)
    print(sum)