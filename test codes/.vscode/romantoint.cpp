#include <iostream>
#include <math.h>
using namespace std;
float num1(float);
int num2(int);

int main()
{
    float a;
    int b;
    cout << "Enter the float number you want the cube: " << endl;
    cin >> a;
    cout << "Cube of the number you have entered: " << num1(a) << endl;
    cout << "Enter the interger number you want the cube: " << endl;
    cin >> b;
    cout << "Cube of the number you have entered: " << num1(b) << endl;

    return 0;
}
float num1(float p)
{
    return pow(p, 3);
}
int num1(int q)
{
    return pow(q, 3);
}