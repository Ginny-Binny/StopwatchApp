fname = input("Enter the name of the file:")
if len(fname)<1: fname="mbox-short.txt"
fhand = open(fname)
dict = dict()

for line in fhand:
    if not line.startswith('From'):continue
    line = line.split()
    line=line[1]
    dict[line]=dict.get(line,0)+1
HC = None
HCW = None
for emailid,senttimes in dict.items():
    if HC == None or senttimes >HC:
        HCW= emailid
        HC=senttimes
print(HCW,HC)
