#include <bits/stdc++.h>
using namespace std;
// base class
class employee
{
public:
    int id;
    float salary;
    employee(int impid)
    {
        id = impid;
        salary = 34.0;
    }
    employee() {}
};

/*
class {{derived-class name}} : {{visibilty-mode}} {{base class name}}{
    //class members functions etc...
};
note;
1) default visibility mode is private
2) public visibility mode: public of base class becomes public of derived class
3) private visibility mode: public of base class becomes private of derived class
4) private members are never inherited
*/

// derived class
class programmer : public employee
{
public:
    int langcode;
    programmer(int impid)
    {
        id = impid;
    langcode = 9;
    }
    void getdata(){
        cout<<id<<endl;
    }
};
int main()
{
    employee rohan(1), harry(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    programmer skillf(10);
    cout<<skillf.id<<endl;
    cout<<skillf.salary<<endl;
    cout<<skillf.langcode<<endl;
    skillf.getdata();
    return 0;
}