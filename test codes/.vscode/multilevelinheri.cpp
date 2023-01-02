#include <bits/stdc++.h>
using namespace std;

class student
{
protected:
    int roll;

public:
    void set_roll(int);
    void get_roll(void);
};

void student::set_roll(int r)
{
    roll = r;
}

void student::get_roll()
{
    cout << "The roll number is: " << roll << endl;
}

class Exam : public student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};
void Exam::set_marks(float m1, float m2)
{
    maths = m1;
    physics = m2;
}
void Exam::get_marks()
{
    cout << "The marks obtained in maths: " << maths << endl;
    cout << "The marks obtained in physics: " << physics << endl;
}

class Result : public Exam{
    float percentage;
    public:
    void display(){
        get_roll();
        get_marks();
        cout<<"Your percentage is: "<<(maths+physics)/2<<"%"<<endl;
    }
};
int main()
{
/*
student is the bas class of Exam
exam is the base class of Result
Student--->Exam--->Result is called inheritance path
*/
    Result k;
    k.set_roll(20);
    k.set_marks(80, 90);
    k.display();
return 0;
}