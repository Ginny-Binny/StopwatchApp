#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int re, im;

public:
    void getdata()
    {
        cout << "enter the real part: ";
        cin >> re;
        cout << "enter the imaginary part: ";
        cin >> im;
    }
    void disp()
    {
        cout << "the number is: " << re << "+" << im << "i" << endl;
    }
    void sum(Complex, Complex);
};

void Complex::sum(Complex c1, Complex c2)
{
    re = c1.re + c2.re;
    im = c1.im + c2.im;
}

int main()
{
    // A obj;
    // obj.disp(obj);

    Complex c1, c2, c3;
    c1.getdata();
    c1.disp();
    c2.getdata();
    c2.disp();
    cout << "the sum of the numbers would be";
    c3.sum(c1, c2);
    c3.disp();
    return 0;
}