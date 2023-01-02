#include <bits/stdc++.h>
using namespace std;

//question one

/*class Person
{
    string name;
    int age;

public:
    Person() {}
    void setdata()
    {
        cout << "Enter name and age: " << endl;
        cin>>name;
        cin >> age;
    }
    void show()
    {
        cout << "Name is: " << name << endl;
        cout << "Age is: " << age << endl;
    }
    int operator >(Person x)
    {
        if (age > x.age){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main()
{
    Person p1,p2,p3;
    p1.setdata();
    p2.setdata();
    p3.setdata();
    Person r;
    if (p1>p2){
        r=p1;
    }
    if(p1>p3){
        r=p1;
    }
    if (p2>p3)
    {
        r=p2;
    }
    else{
        r=p3;
    }
    r.show();
    return 0;
}*/

//question 2
 /*class sample{
    public:
    int num;
    void getnum(){
        cout<<"Enter the number: ";
        cin>>num;
    }
    void putnum(){
        cout<<"The value of the numbar is: "<<num<<endl;
    }
 };
int main()
{
    int n;
    cout<<"Enter the number of objects you wanted to create: ";
    cin>>n;
    sample* ptr = new sample[n];
    sample* temp=ptr;
    for (int i = 0; i <n; i++)
    {
        (ptr)->getnum();
        ++ptr;
    }
    for (int j = 0; j <n; j++)
    {
        (temp)->putnum();
        ++temp;
    }
    return 0;
}*/

// question 3
class media{
    protected:
    string name;
    float price;
    public:
    media(){}
    media(string s, float p){
        name = s;
        price=p;
    }
    virtual void display(){}
};
class book: public media{
    int pages;
    public:
    book(string s, float p, int pa): media(s,p){
        pages=pa;
    }
    void display(){
        cout<<endl;
        cout<<"The name of the book is: "<<name<<endl;
        cout<<"And the price and pages of the book is: "<<price<<" "<<pages<<endl;
    }
};
class tape: public media{
    float time;
    public:
    tape(string s, float p, float t): media(s,p){
        time=t;
    }
     void display(){
         cout<<endl;
        cout<<"The name of the book is: "<<name<<endl;
        cout<<"And the price and time of the book is: "<<price<<" "<<time<<endl;
    }
};
int main()
{
    string name;
    float time, price;
    int npage;

    // for book
    cout<<"Enter the name, price and number of pages in the same order for book: "<<endl;
    cin>>name;
    cin>>price>>npage;
    book b(name, price, npage);
    
    // for tape
    cout<<"Enter the name, price and time of play in the same order for tape: "<<endl;
     cin>>name;
    cin>>price>>time;
    tape t(name,price,time);

    media* ptr[2];
    ptr[0] = &b;
    ptr[1] = &t;

    ptr[0]->display();
    ptr[1]->display();
    return 0;
}
