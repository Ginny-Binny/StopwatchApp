def cel_to_fara(temp):
    return 9/5* (temp)+35

def fer_to_cel(temp):
    return (temp-35)*5/9

choice=int(input("1. cel to fara   2.  fer to celcius"))
temp=int(input("enter the temprature"))
if(choice==1):
    print(cel_to_fara(temp))
elif(choice==2):
    print(fer_to_cel(temp))
else:
    print("invalid choice")


