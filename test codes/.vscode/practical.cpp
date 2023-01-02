#include <bits/stdc++.h>
using namespace std;

class hall{
    static int num;
    char name[50];
    public:
    void getdata(){
        cout<<"Enter the name of the guest"<<endl;
        cin>>name;
    }
    void show(){
        increment();
        cout<<"Name of the guest is "<<name<<" and the seat allocated is "<<num<<" enjoy the show"<<endl<<endl;
    }
    static void increment(){
        num=num+1;
    }
};

int hall::num;

int main(){
    int n;
    cout<<"Enter the number of guest you wanted to accomodate limit is 50: ";
    cin>>n;
    hall k[n];
    for (int i = 0; i < n; i++)
    {
        k[i].getdata();
    }
    cout<<"The seating manner would be: "<<endl<<endl;
    for (int j = 0; j < n; j++)
    {
        k[j].show();
    }

return 0;
}

// class Find
// {
// private:
//     float a, b, xy;

// public:
//     void getdata()
//     {
//         cout << "Enter the 2 float numbers: ";
//         cin >> a >> b;
//     }
//     inline void multi()
//     {
//         xy = a * b;
//         cout << "The multiplication is: " << xy << endl;
//     }

//     inline void flor()
//     {
//         xy = a / b;
//         cout << "The floor divition is: " << xy << endl;
//     }
// };

// int main()
// {
//     Find a;
//     a.getdata();
//     a.multi();
//     a.flor();
//     return 0;
// }
