#include <bits/stdc++.h>
using namespace std;

/*int main(){
    string st1,st2;
    ifstream mainfile;
    ofstream copyfile;
    string mainfilename, copyfilename;
    cout<<"Enter the name of the file from which you want to copy: "<<endl;
    cin>>mainfilename;
    cout<<"Enter the name of the fie in which you want to copy the s1: "<<endl;
    cin>>copyfilename;
    mainfile.open(mainfilename, ios::out);
    copyfile.open(copyfilename, ios::in);

    while (mainfile.eof()==0)
    {
        getline(mainfile,st1);
        copyfile<<st1<<"\n";
    }
    cout<<"End program";
return 0;
}*/

// question 2

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
    andar.open("fileIO1.txt", ios::out | ios::in);
    andar.read((char*)&s2, sizeof(s2));
    s2.showdata();
    andar.close();
    return 0;
}
