print("Name: Aditi Mehra")
print("UID: 20BCS4806")
from heapq import nlargest
my_dict = {'a':500, 'b':5874, 'c': 560,'d':400, 'e':5873, 'f': 20}
three_largest = nlargest(3, my_dict, key=my_dict.get)
print(three_largest)
