#include <bits/stdc++.h>
using namespace std;

//unary operator
/*class Complex{
    int a,b;
    public:
    void getvalue(){
        cout<<"Enter two numbers: "<<endl;
        cin>>a>>b;
    }
    void operator --(){
        a=--a;
        b=--b;
    }
    void operator ++(){
        a=++a;
        b=++b;
    }
    void display(){
        cout<<a<<"+"<<b<<"i"<<endl;
    }
};

int main(){
    Complex c1;
    c1.getvalue();
    --c1;
    cout<<"Decremented complex nymber is;";
    c1.display();
    ++c1;
    cout<<"Incremented complex number is:";
    c1.display();

return 0;
}*/

// overloading post increment using friend function
/*class post{
    int x;
    public:
    void get(){
        cout<<"Enter the number: ";
        cin>>x;
    }
    void put(){
        cout<<"The number is: "<<x;
    }

    friend post operator ++(post,  int);
};

post operator ++(post obj, int a){
    post temp;
    obj.x++;
    temp.x = obj.x;
    return temp;
}

int main(){
    post p1, p2;
    cout<<"Enter the value: ";
    p1.get();
    p2=p1++;
    cout<<"After increment: ";
    p2.put();
    return 0;
}*/

//overloading binary operator

/*class Complex{
    int re, im;
    public:
    Complex(): re(0), im(0){}
    void input(){
        cout<<"Enter the real and imaginary part: "<<endl;
        cin>>re>>im;
    }
    Complex operator -(Complex c2){
        Complex t;
        t.re=re-c2.re;
        t.im=im-c2.im;
        return t;
    }
    void output(){
        cout<<"The number is: "<<re<<" + "<<im<<"i"<<endl;
    }
};
int main()
{
    Complex c1,c2,c3;
    cout<<"Enter the first number: "<<endl;
    c1.input();
    cout<<"Enter the second number: "<<endl;
    c2.input();
    c3=c1-c2;
    c3.output();
    return 0;
}*/

// to add tow numbers using operatoe overloading;

class add
{
public:
    int x;
    void get()
    {
        cout << "Enter the number: " << endl;
        cin >> x;
    }
    void put()
    {
        cout << "the number is: "<<x<< endl;
    }
    add operator+(add o)
    {
        add ob;
        ob.x = x + o.x;
        return ob;
    }
};
int main()
{
    add a1, a2, a3;
    a1.get();
    a2.get();
    a3 = a1 + a2;
    a3.put();
    return 0;
}
