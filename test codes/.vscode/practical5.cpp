#include <bits/stdc++.h>
using namespace std;

/*class staff
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
        cout << "Enter the subject: ";
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
}*/


/*class Student
{
protected:
    char uid[10];

public:
    void getnumber()
    {
        cout<<"Enter the uid: ";
        cin>>uid;
    }
    void putnumber()
    {
        cout << "\t\t The UID is: " << uid << endl;
    }
};

class Test : virtual public Student
{
protected:
    float MST1, MST2;

public:
    void getmarks()
    {
       cout<<"Enter the marks in MST1: ";
       cin>>MST1;
       cout<<"Enter the physics in MST2: ";
       cin>>MST2;
    }
    void showmarks(void)
    {
        cout << "\t\t your result is: "<<endl
             << "\t\t MST1: " << MST1 << endl
             << "\t\t MST2: " << MST2 << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void getscore()
    {
        cout<<"Enter the score: ";
        cin>>score;
    }
    void putscore()
    {
        cout << "\t\t Your score is: " << score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display()
    {
        total = MST1 + MST2 + score;
        cout<<endl<<endl;
        putnumber();
        showmarks();
        putscore();
        cout << "\t\t Your total score is: " << total << endl;
    }
};

int main()
{
    Result k;
    k.getnumber();
    k.getmarks();
    k.getscore();
    k.display();
    return 0;
}*/


class alpha{
    protected:
    float a;
    public:
    alpha(float i){
        a=i;
        cout<<"alpha constructoe is called"<<endl<<endl;
    }
    void printalpha(){
        cout<<"The variable inside alpha is: "<<a<<endl;
    }
};

class beta{
    protected:
    int b;
    public:
    beta(int j){
        b=j;
        cout<<"beta constructoe is called"<<endl<<endl;
    }
    void printbeta(){
        cout<<"The variable inside beta is: "<<b<<endl;
    }
};

class gama : public beta,  public alpha{
    protected:
    int c, d;
    public:
    gama(float m, int n, int o, int p): alpha(m),beta(n){
        c=o;
        d=p;
        cout<<"gama constructor is called"<<endl<<endl;
    }
    void printgama(){
        cout<<"The variable inside gama are: "<<c<<endl;
        cout<<"The variable inside gama are: "<<d<<endl;
    }

};


int main()
{
    gama k(20.4, 3, 5, 7);
    k.printalpha();
    k.printbeta();
    k.printgama();

    return 0;
}