#include<iostream>
#include<fstream>
using namespace std;
class student
{
public:
    char st[20];
    int age, roll;
    void getdata(void)
    {
        cout << "Enter name of the student: " << endl;
        cin.getline(st,50);
        cout << "Enter the age and roll number: " << endl;
        cin>>age>>roll;
       
    }
    void showdata(void)
    {
        cout << "The name, age and roll number of the student is: " << endl;
        cout << st<<"  "<< age <<"  "<< roll << endl;
    }
};
int main()
{
    student s1;
    fstream andar;
    andar.open("fileIO1.txt", ios::out | ios::in);
    if (!"fileIO1.txt")
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
    s1.showdata();
    return 0;
}