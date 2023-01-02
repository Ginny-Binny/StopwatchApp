#include <iostream>
#include<fstream>
using namespace std;

int main ()

{

int l;

char * b;

ifstream i;

i.open ("find.txt", ios :: binary );

i.seekg (0, ios :: end);

l = i.tellg();

i.seekg (0, ios :: beg);

b = new char [l];

i.read (b, l);

i.close();

cout.write (b, l);

delete[] b;

return 0;

}