numb=int(input("Enter the number of "))
for i in range(0 ,numb+1):
    for j in range(0 ,i):
        print(chr(64+i),end=" ")
    print()