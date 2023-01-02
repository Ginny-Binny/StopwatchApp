#include <bits/stdc++.h>
using namespace std;

class b;

class a
{
    int val1;
    friend void exchange(a&, b&);
    public:
        void indata(int c)
        {
            val1 = c;
        }
        void display(void){
            cout<<val1<<endl;
        }
};

class b
{
    int val2;
    friend void exchange(a&, b&);
    public:
        void indata(int c)
        {
            val2 = c;
        }
        void display(void){
            cout<<val2<<endl;
        }
};

void exchange(a & x, b & y){
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main()
{
    a oa;
    b ob;
    oa.indata(34);
    cout<<"value before replacing: ";
    oa.display();
    ob.indata(54);
    cout<<"value before replacing: ";
    ob.display();
    exchange(oa,ob);
    cout<<"the value after repalcing is: ";
    oa.display();
    cout<<"the value after repalcing is: ";
    ob.display();
    return 0;
}