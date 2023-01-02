#include<iostream>
using namespace std;

class Add {
   int s;
public:

   Add(int a, int b) {
       s = a + b;
   }

   void display() {
       cout << "the Sum of the two numberrs is:" << s;
   }
};

int main() {

   int a, b;

   cout << "Enter two numbers:";
   cin >> a >> b;

   Add obj(a, b);
   obj.display();

   return 0;
}