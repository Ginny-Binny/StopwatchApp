#include <bits/stdc++.h>
using namespace std;

// calling global and local variable

int x=23;
int main()
{
    int x=2;
    cout<<"the global variable is: "<<::x<<endl;
    cout<<"the local variable is: "<<x<<endl;
    return 0;
}


// memory address of the array element 
/*int main()
{
    int m, n, lc = 0, lr = 0, b, w,i, j;
    int arr[5][5];
    cout << "enter the number of rows: ";
    cin >> n;
    cout << "enter the number of columns: ";
    cin >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "enter the arry element: "<<i <<j <<": ";
            cin >> arr[i][j];
        }
    }
    cout << "enter the base address: ";
    cin >> b;
    cout << "enter the storage size of the element: ";
    cin >> w;
    i = n - 1;
    j = m - 1;
    cout << "address of A[i][j]: " << b + w * (m * (i - lr) + (j - lc));

    return 0;
}*/


//practical one of 2.1
class employee
{
private:
    char name[20];
    int age;
    char desi[10];
    long salary;
public:
    void getdata();
    void putdata();
};

void employee::getdata()
{
    cout << "enter the name: ";
    cin>>name;
    cout << "enter the age of the employee: ";
    cin >> age;
    cout << "enter the designation of the employee: ";
    cin >> desi;
    cout << "enter the salary of the employee: ";
    cin >> salary;
}
void employee::putdata()
{
    cout << "\n\n\n";
    cout <<"name of the employee is: "<< name << endl;
    cout <<"name of the employee is: "<< age << endl;
    cout <<"name of the employee is: "<< desi << endl;
    cout <<"name of the employee is: "<< salary << endl;
}

int main()
{
    employee arr[3];
    for (int i = 0; i <= 2; i++)
    {
        arr[i].getdata();
    }

    for (int j = 0; j <= 2; j++)
    {
        arr[j].putdata();
    }
    return 0;
}