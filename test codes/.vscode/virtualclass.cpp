#include <bits/stdc++.h>
using namespace std;

class Student
{
protected:
    int roll;

public:
    void setnumber(int a)
    {
        roll = a;
    }
    void printnum()
    {
        cout << "the roll number is: " << roll << endl;
    }
};

class Test : virtual public Student
{
protected:
    float maths, physics;

public:
    void setmarks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void showmarks(void)
    {
        cout << "your result is: "
             << "maths: " << maths << endl
             << "physics: " << physics << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(int sc)
    {
        score = sc;
    }
    void printscore()
    {
        cout << "Yout score is: " << score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display()
    {
        total = maths + physics + score;
        printnum();
        showmarks();
        printscore();
        cout << "Your total score is: " << total << endl;
    }
};

int main()
{
    Result k;
    k.setnumber(2344);
    k.setmarks(50,79);
    k.set_score(9);
    k.display();
    return 0;
}