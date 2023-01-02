numb=int(input("Enter the number of "))
counter=1
for i  in range(0,numb+1):
    for j in range(0, i):
        print(counter, end=" ")
        counter +=1
    print()