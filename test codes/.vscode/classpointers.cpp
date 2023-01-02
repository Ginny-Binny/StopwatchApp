#include <bits/stdc++.h>
using namespace std;

// normal pointer
/*class Complex{
    int real, imaginary;
    public:
    void getdata(){
        cout<<"The real part is: "<<real<<endl;
        cout<<"The imaginary part is: "<<imaginary<<endl;
    }
    void setdata(int a, int b){
        real = a;
        imaginary = b;
    }
};
int main(){
    // Complex c1;
    // Complex *ptr = &c1;
    // (*ptr).setdata(1,5);
    // ptr->getdata();


    Complex *ptr1 = new Complex[4];
    ptr1->setdata(3,7);
    (ptr1)->getdata();
    (ptr1+1)->setdata(4,7);
    (ptr1+1)->getdata();

return 0;
}*/

// aray of a pointers
/*class shop
{
    int id;
    float price;
    public:
        void setdata(int a, float b){
            id = a;
            price = b;
        }
        void getdata(){
            cout<<"The id of the item is: "<<id<<endl;
            cout<<"The price of the item is: "<<price<<endl;
        }
};

int main()
{
    shop *ptr = new shop[3];
    shop *ptrtemp = ptr;
    int p;
    float q;
    for (int i = 0; i < 3; i++)
    {
        cout<<"id and price of item one: "<<i+1<<endl;
        cin>>p>>q;
        (ptr)->setdata(p, q);
        ptr++;
    }
    for (int j = 0; j <3; j++)
    {
        cout<<"Item number: "<<j+1<<endl;
        (ptrtemp)->getdata();
        ptrtemp++;
    }
    
    return 0;
}*/

// this pointer
/*class A{
int a;
    public:
        void setdata(int a){
            this->a=a;
        }
        void getdata(){
            cout<<"The value of a is: "<<a<<endl;
        }
};

int main()
{
    A a;
    a.setdata(4);
    a.getdata();
    return 0;
}*/

// pointer in derived class
/*class Baseclass{
    public:
    int var_base;
    void display(){
        cout<<"Display base class variable vare_base: "<<var_base<<endl;
    }
};

class Derivedclass: public Baseclass{
    public:
    int var_derived;
    void display(){
        cout<<"Display base class variable vare_base: "<<var_base<<endl;
        cout<<"Display derived class variable vare_derived: "<<var_derived<<endl;
    }
};
int main()
{
    Baseclass * base_class_pointer;
    Baseclass obj_base;
    Derivedclass obj_derived;
    base_class_pointer = &obj_derived; // pointing to derived class

    base_class_pointer->var_base=344;
    //base_class_pointer->var_derived=344;  error
    base_class_pointer->display();
    Derivedclass * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_derived=100;
    derived_class_pointer->display();
    return 0;
}*/

// virtual function
class Baseclass{
    public:
    int var_base=1;
    virtual void display(){
        cout<<endl<<endl;
        cout<<"1 Display base class variable vare_base: "<<var_base<<endl;
    }
};

class Derivedclass: public Baseclass{
    public:
    int var_derived=2;
    void display(){
        cout<<endl<<endl;
        cout<<" 2Display base class variable vare_base: "<<var_base<<endl;
        cout<<" 2Display derived class variable vare_derived: "<<var_derived<<endl;
    }
};

int main()
{
    Baseclass  * base_class_pointer;
    Baseclass obj_base;
    Derivedclass obj_derived;

    base_class_pointer = &obj_base;
    base_class_pointer->var_base=30;
    base_class_pointer->display();
    return 0;
}
