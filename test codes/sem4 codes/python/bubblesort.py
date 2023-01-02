l= [11,4,52,55,32,56,6,100,100]


def BS(l):

   for j in range(len(l)-1,0,-1):

       for i in range(j):

           if l[i]>l[i+1]:

               temp = l[i]

               l[i] = l[i+1]
  
               l[i+1] = temp
BS(l)
print(l)


    