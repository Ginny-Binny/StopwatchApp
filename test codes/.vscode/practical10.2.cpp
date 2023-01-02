#include <bits/stdc++.h>
using namespace std;
class student
{
public:
    char st[20];
    int age, roll;
    void getdata()
    {
        cout << "Enter name of the student: " << endl;
        cin.getline(st,20);
        cout << "Enter the age and roll number: " << endl;
        cin>>age;
        cin>>roll;
    }
    void showdata()
    {
        cout << "The name, age and roll number of the student is: " << endl;
        cout << st << endl
             << age << endl
             << roll << endl;
    }
};
int main()
{
    student s1,s2;
    fstream andar;
    andar.open("testfilefor10.2.txt", ios::out | ios::in);
    if (!"testfilefor10.2.txt")
    {
        cout << "Can't create file" << endl;
    }
    else
    {
        cout << "File created succesfully" << endl;
    }
    s1.getdata();
    andar.write((char *)&s1, sizeof(s1));
    andar.close();
    andar.open("testfilefor10.2txt", ios::out | ios::in);
    andar.read((char*)&s2, sizeof(s2));
    s2.showdata();
    andar.close();
    return 0;
}

