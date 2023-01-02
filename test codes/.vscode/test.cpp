#include <bits/stdc++.h>
using namespace std;

class staff
{
protected:
    int code;
    char name[20];

public:
    void getstaff()
    {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the code: ";
        cin >> code;
    }

    void putstaff()
    {
        cout << "\t\t The name is: " << name << endl;
        cout << "\t\t The code is: " << code << endl;
    }
};

class teacher : public staff
{
    char sub[20];
    char publi[20];

public:
    void make()
    {
        getstaff();
        cout << "Enter the subject: "<<endl;
        cin >> sub;
        cout << "Enter the publication: ";
        cin >> publi;
    }
    void display()
    {
        putstaff();
        cout << "\t\t Subject: " << sub << endl;
        cout << "\t\t Publication: " << publi << endl;
    }
};

class officer : public staff
{
    char grade[2];

public:
    void make()
    {
        getstaff();
        cout << "Enter the grade: ";
        cin >> grade;
    }
    void display()
    {
        putstaff();
        cout << "\t\t grade: " << grade << endl;
    }
};

class typist : public staff
{
    int speed;
    float wage;

public:
    void make()
    {
        getstaff();
        cout << "Enter the speed according to wpm: ";
        cin >> speed;
        cout << "Enter the wages per day: ";
        cin >> wage;
    }
    void display()
    {
        putstaff();
        cout << "\t\t speed: " << speed << endl;
        cout << "\t\t wage: " << wage << endl;
    }
};

int main()
{
    teacher t;
    officer o;
    typist ty;
    char con = 'y';
    int choice;
    do
    {
        cout << "What do you want to take in you school: " << endl;
        cout << "1 for teacher" << endl
             << "2 for officer" << endl
             << "3 for typist" << endl;
        cin >> choice;
        if (choice == 1)
        {
            t.make();
            cout<<endl<<endl;
            t.display();
        }

        if (choice == 2)
        {
            o.make();
            cout<<endl<<endl;
            o.display();
        }

        if (choice == 3)
        {
            ty.make();
            cout<<endl<<endl;
            ty.display();
        }
        cout << "Press y to continue or n to end the program: ";
        cin >> con;
        if (con != 'y')
        {
            return 0;
        }
    } while (con == 'y');

    return 0;
}
