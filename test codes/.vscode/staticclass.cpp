#include <bits/stdc++.h>
using namespace std;

// class is the property of class

class employee
{
    int id;
    static int count; //assign to 0 by default
public:
    void getdata(void)
    {
        cout << "enter the id: " << endl;
        cin >> id;
    }
    void setdata(void)
    {
        cout << "the id of the emplyee is: " << id << " and thid is employee number: " << count + 1 << endl;
        count++;
    }

    static void getcount(void){
        cout<<"the value of count is: "<<count<<endl;
    }
};

int employee::count;

int main()
{
    employee kshitij, rohan, lovish;
    kshitij.getdata();
    kshitij.setdata();
    employee::getcount();

    rohan.getdata();
    rohan.setdata();
    employee::getcount();

    lovish.getdata();
    lovish.setdata();
    employee::getcount();

    return 0;
}
