E=float(input("enter english marks"))
C=float(input("enter chemistry marks"))
M=float(input("enter maths marks"))
P=float(input("enter physics marks"))
H=float(input("enter hindi marks"))
def get_marks(E,C,M,P,H):
    return E,C,M,P,H
def display(E,C,M,P,H):
    print(E,C,M,P,H)
def average(E,C,M,P,H):
    avg = float((E+C+M+P+H)/5)
    print(avg)
get_marks(E,C,M,P,H)
display(E,C,M,P,H)
average()
