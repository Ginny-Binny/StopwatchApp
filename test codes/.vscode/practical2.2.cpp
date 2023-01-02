#include<iostream>

using namespace std;
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
