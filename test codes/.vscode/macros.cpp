#include <bits/stdc++.h>
using namespace std;

/*int constant=0;
class abhilaksh
{
   static int times;
   int arr[10];
public:
   void howmany(void)
   {
      cout<<"enter the number:";
      cin>>arr[10];
      times++;
   }
   void display(void);
};
int abhilaksh::times;

void abhilaksh::display(void)
{
   cout << "I have been called: " << times << " times"<<endl;
}

int main()
{
   int incre=0;
   abhilaksh a[10];
   for (int i = 0; i <= 9; i++)
   {
      a[i].howmany();
      incre++;
   }
   a[incre].display();
   return 0;
}*/

/*int constant=0;
class abhilaksh
{
   int arr[1];
public:
   void howmany(void)
   {
      cout<<"enter the number:";
      cin>>arr[1];
      constant++;
   }
   void display(void);
};

void abhilaksh::display(void)
{
   cout << "I have been called: " << constant << " times"<<endl;
}

int main()
{
   int incre=0;
   abhilaksh a[10];
   for (int i = 0; i <= 9; i++)
   {
      a[i].howmany();
      incre++;
   }
   a[incre].display();
   return 0;
}*/

/*class box{
   int l,b,h,vol;
   public:
   void getdata();
   void calc(void){
      vol=l*b*h;
      cout<<"Volume of the box is:- "<<vol<<endl;
   }
};
void box::getdata(){
    cout<<"Enter the lenght of the box:- "<<endl;
   cin>>l;
   cout<<"Enter the breadht of the box:- "<<endl;
   cin>>b;
   cout<<"Enter the height of the box:- "<<endl;
   cin>>h;
}

int main()
{
   int volume;
   box dabba;
   dabba.getdata();
   dabba.calc();
   return 0;
}*/

/*class calc
{
   float a, b;

public:
   inline void multi();
   inline void divide();
   void getdata()
   {
      cout << "enter the 2 numbers: " << endl;
      cin >> a >> b;
   }
};

void calc::multi()
{
   cout << "the multiplication of two nembers is: " << a * b << endl;
}
void calc::divide()
{
   cout << "the division of two nembers is: " << a / b << endl;
}

int main()
{
   calc c1;
   c1.getdata();
   c1.multi();
   c1.divide();
   return 0;
}*/

/*class demo
{
   string name;
   int hi;
   int w;

public:
   demo() {}
   demo(string, int, int);
   void display()
   {
      cout << "The name is: " << name << endl;
      cout << "The hight is: " << hi << endl;
      cout << "The weight is: " << w << endl;
   }
};
demo::demo(string s, int x, int y){
   name=s;
   hi=x;
   w=y;
}
int main()
{
   string name;
   int w,h;
   cout<<"Enter the name: ";
   getline(cin,name);
   cout<<"enter height and weight: "<<endl;
   cin>>h>>w;
   demo student(name,h,w);
   student.display(); 
   return 0;
}*/


class calcualtion
{
   int x, y, ad = 0;
   char c;

public:
   void multi(int a, int b)
   {
      x = a;
      y = b;
      ad = a * b;
      cout << "The multiplication is: " << ad << endl;
   }

   void flor(int a, int b)
   {
      x = a;
      y = b;
      ad = a / b;
      cout << "The floor divition is: " << ad << endl;
   }

   void mod(int a, int b)
   {
      x = a;
      y = b;
      ad = a % b;
      cout << "The mudulus is: " << ad << endl;
   }

   void sub(int a, int b)
   {
      x = a;
      y = b;
      ad = a - b;
      cout << "The subtraction is: " << ad << endl;
   }

   void add(int a, int b)
   {
      x = a;
      y = b;
      ad = a + b;
      cout << "The addition is: " << ad << endl;
   }
};

int main()
{
   char condi = 'y';
   calcualtion num;
   char c;
   int a, b;
   cout << "you can do *, -, +, %, / operations" << endl;

   do
   {
      cout << "Enter the number in the (number opreration number)format: " << endl;
      cin >> a;
      cin >> c;
      cin >> b;
      if (c == '+')
      {
         num.add(a, b);
      }
      if (c == '-')
      {
         num.sub(a, b);
      }
      if (c == '*')
      {
         num.multi(a, b);
      }
      if (c == '/')
      {
         num.flor(a, b);
      }
      if (c == '%')
      {
         num.mod(a, b);
      }
      cout << "Enter condition:";
      cin >> condi;
   } while (condi == 'y');
   return 0;
}


