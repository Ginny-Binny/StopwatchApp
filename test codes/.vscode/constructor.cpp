#include<iostream>
using namespace std;

int main()
{
    cout<<"hello guys "<< endl;
    return 0;
}
 int);
    void pritndata()
    {
        cout << "your number is " << a << " + " << b << "i" << endl;
    }
};

Complex::Complex(int x, int y)
{
    a = x;
    b = y;
    // cout << "your number is " << a << " + " << b << "i"<< endl;
}

int main()
{
    Complex a(4, 7); //implicit call
    a.pritndata();

    // explicit call
    Complex b = Complex(4, 7);
    b.pritndata();
    return 0;
}