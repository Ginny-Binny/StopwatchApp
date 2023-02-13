b="Hello World"
cat(b)
print(class(b))

new_b= charToRaw(b)
cat(new_b)
cat(class(new_b))  #gives the byte value of our string.