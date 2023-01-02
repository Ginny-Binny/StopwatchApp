#include <bits/stdc++.h>
using namespace std;

//single inhritance
/*class base
{
    int data1;

public:
    int data2;
    void setdata();
    int getdata1();
    int getdata2();
};

void base::setdata(void)
{
    data1 = 10;
    data2 = 20;
}

int base::getdata1()
{
    return data1;
}

int base::getdata2()
{
    return data2;
}

class derived : public base
{
    int data3;

public:
    void process();
    void display();
};

void derived::process()
{
    data3 = data2 * getdata1();
}
void derived::display(){
    cout<<"Vaue of data1 is"<<getdata1()<<endl;
    cout<<"Vaue of data2 is"<<data2<<endl;
    cout<<"Vaue of data3 is"<<data3<<endl;
}
int main()
{
    derived der;
    der.setdata();
    der.process();
    der.display();
    return 0;
}*/

//protected
class Base{
protected:
private:
    int b;
    public:
    int a;
    void out(void){
        a=10;
        cout<<a;
    }
};

class Derived : protected Base{
    
};

int main()
{
    Base b;
    Derived d;
    d.out();
    return 0;
}
