#include <bits/stdc++.h>
using namespace std;

// question one
/*class area{
    int len, bre, ar;
    public:
    area(void);
    area(int, int);
    ~area();
    void calc(){
        ar=len*bre;
        cout<<"Area is:"<<ar<<endl;
    }
};

area::area(void){
    len = 3;
    bre = 5;
}

area::area(int x, int y){
    len = x;
    bre = y;
}

area::~area(){
    cout<<"object is bieng deleted"<<endl;
}

int main(){
    int l,b;
    area o1;
    o1.calc();
    cout<<"enter the value of length and breadth: ";
    cin>>l>>b;
    area o2(l,b);
    o2.calc();

    return 0;
}*/
// question two
class details
{
    string name;
    int roll;
    int hi;
    int wei;

public:
    details();
    details(string, int, int, int);
    ~details()
    {
        cout << "distructor is called";
    }
    void display()
    {
        cout << "name of the student is: " << name << endl
             << "Roll number is: " << roll << endl
             << "Hight: " << hi << endl
             << "weight: " << wei << endl;
    }
};

details::details(string a, int b, int c, int d)
{
    name = a;
    roll = b;
    hi = c;
    wei = d;
}

int main()
{
    details s("Kshitij Kumar", 4094, 178, 80);
    details s1 = s;
    s1.display();
    return 0;
}
