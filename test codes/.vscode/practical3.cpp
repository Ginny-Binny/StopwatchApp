#include <bits/stdc++.h>
using namespace std;

/*#define MAX(a,b,c)(a>b&&a>c?a:(b>c?b:c))
#define MIN(a,b,c)(a<b&&a<c?a:(b<c?b:c))

int main(){
    int a,b,c;
    cout<<"enter the three numbers:"<<endl;
    cin>>a>>b>>c;
    int large=MAX(a,b,c);
    int small=MIN(a,b,c);
    cout<<"the largest among three numbers is: "<<large<<endl;
    cout<<"the smallest among three numbers is: "<<small<<endl;
    
    return 0;
}*/

//question 2
class b;

class a
{
private:
    int num1;

public:
    void getdata()
    {
        cout << "enter the value of the variable for class one: ";
        cin >> num1;
    }
    friend void swapclass(a, b);
};

class b
{
private:
    int num2;

public:
    void getdatab()
    {
        cout << "enter the value of the variable for class two: ";
        cin >> num2;
    }
    friend void swapclass(a, b);
};

void swapclass(a one,b two)
{
    int temp = one.num1;
    one.num1 = two.num2;
    two.num2 = temp;
    cout << "the changed privte vlaue is:" << endl;
    cout << "for class a: " << one.num1 << endl;
    cout << "for class b: " << two.num2 << endl;
}

int main()
{
    a first;
    b second;
    first.getdata();
    second.getdatab();
    swapclass(first, second);
    return 0;
} 

// question 3

class Complex{
private:
int re,im;
public:
void getdata();
void putdata();
void putsum();
friend Complex sum(Complex, Complex);
};

void Complex::getdata(){
cout<<"Enter the real and imaginary part if the number: "<<endl;
cin>>re>>im;
}
void Complex::putdata(){
    cout<<"the entered number is: "<<re<<" + "<<"i"<<im<<endl;
}
void Complex::putsum(){
    cout<<"the sum is: "<<re<<" + "<<"i"<<im;
}
Complex sum(Complex c1, Complex c2){
    Complex c3;
    c3.re =c1.re+c2.re;
    c3.im=c1.im+ c2.im;
    return c3;

}

int main()
{
    Complex c1,c2,c3;
    c1.getdata();
    c1.putdata();

    c2.getdata();
    c2.putdata();
    c3=sum(c1,c2);
    c3.putsum();
    return 0;
}
