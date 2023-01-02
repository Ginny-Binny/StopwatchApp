#include <iostream>
#include <math.h>
using namespace std;

// program for factorial
// int main()
// {
//     int n,fact=1;
//     cout<<"enter the number of which you want factorial: ";
//     cin>>n;
//     for (int i = 1; i <= n; i++)
//     {
//         fact *= i;
//     }
//     cout<<"the factorial of " <<n<< "\nis "<<fact;
//     return 0;
// }

//program that takes input of desired number of marks and gives total and average
// int main()
// {
//     int marks,sub;
//     float total=0.0, average=0.0;
//     cout<<"Enter the nuamber of subjects: ";
//     cin>>sub;
//     for (int i = 1; i <= sub; i++)
//     {
//         cout<<"enter the marks of subject "<<i<< " : ";
//         cin>>marks;
//         total += marks;
//     }
//     cout<<"total is: "<<total<<"\n";
//     average=total/sub;
//     cout<<"average is: "<<average;
//     return 0;
// }

int main()
{
    int number, last, first, digit, a, b, swapped;
    cout << "enter the number of which you wannt to swap the first and last digit: ";
    cin >> number;
    last = number % 10;
    digit = (int)log10(number);
    first = number / pow(10, digit);
    a = first * pow(10, digit);
    b = number % a;
    number = b / 10;
    swapped = last * (pow(10, digit)) + (number * 10 + first);
    cout << "the number is after swapping first and last number:"<<endl;
    cout << swapped<<endl;
    return 0;
}
