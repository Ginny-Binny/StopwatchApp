print("Name: Gaurang Sharma")
print("UID: 20BCS4133")
def check_in_tuples(colors, c): 
    result = any(c in tu for tu in colors)     
    return result 
colors = (    
    ('Red', 'White', 'Blue'), 
    ('Green', 'Pink', 'Purple'), 
    ('Orange', 'Yellow', 'Lime'),)

print("Original list:") 
   
print(colors) 
c1 = 'White' 
 
print("\nCheck if",c1,"presenet in said tuple of tuples!") 
print(check_in_tuples(colors, c1)) 
c1 = 'White' 
print("\nCheck if",c1,"presenet in said tuple of tuples!") 
print(check_in_tuples(colors, c1)) 
c1 = 'Olive' 
print("\nCheck if",c1,"presenet in said tuple of tuples!") 
print(check_in_tuples(colors, c1)) 


