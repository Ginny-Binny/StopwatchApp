#include <bits/stdc++.h>
using namespace std;

//question 1
/*class funcoverload{
    float x, y;
    public:
    double fun(double a, double b){
        x=a;
        y=b;
        return x+y;
    }
    int fun(int a, int b){
        x=a;
        y=b;
        return x+y;
    }
};
int main(){
    double b;
    int c;
    funcoverload a;
    b=a.fun(5.2, 5.5);
    cout<<"the float sum is: "<<b<<endl;
    c=a.fun(5, 5);
    cout<<"the int sum is: "<<c<<endl;
return 0;
}*/

//question 2

/*class test
{
    int num;

public:
    test(): num(0){}
    void put()
    {
        cout << "The number is: " << num << endl;
    }
    test(int n)
    {
        num = n;
    }
    //prefix
    test operator++()
    {
        ++num;
        return test(num);
    }
    //postfix
    test operator++(int)
    {
        test x(num);
        num++;
        return x;
    }
};
int main()
{
    test a(4), b(4), c;
    ++a;
    a.put();
    b++;
    b.put();
    c.put();
    c = b++;
    b.put();
    c.put();
    return 0;
}*/

// question 3

/*#define R 4
#define C 4
class Matrix
{
public:
    int a[R][C];
    int rows, col;
    Matrix()
    {
        rows = col = 2;
    };
    Matrix(int r, int c, int arr[R][C])
    {
        rows = r;
        col = c;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = arr[i][j];
            }
        }
    }

    Matrix operator+(Matrix x)
    {
        if (x.rows != rows || x.col != col || (rows == 0 && col == 0))
        {
            return Matrix();
        }
        int mat[R][C];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = a[i][j] + x.a[i][j];
            }
        }
        return Matrix(rows, col, mat);
    }

    int operator==(Matrix x)
    {
        if (x.rows != rows || x.col != col)
        {
            return 0;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (a[i][j] != x.a[i][j])
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    void show(void)
    {
        for (int i = 0; i < rows; i++)
        {
            cout<<"|";
            for (int j = 0; j < col; j++)
            {
                cout <<setw(4)<< a[i][j] << " ";
            }
            cout <<"|"<< endl;
        }
        cout << endl;
    }
};

int main()
{
    int arr1[R][C], arr2[R][C];
    int r, c;
    cout << "Enter the value of rows and colums for both matrix: " << endl;
    ;
    cin >> r >> c;
    cout << "Enter the value for matrix 1: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "Enter the value for matrix 2: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr2[i][j];
        }
    }
    Matrix m1(r, c, arr1);
    Matrix m2(r, c, arr2);
    Matrix m4(r, c, arr2);
    Matrix m3;
    cout<<"Matrix 1 and 2 are: "<<endl<<endl;; 
    m1.show();
    m2.show();
    m3 = m1 + m2;
    cout<<"Sum of matrix and 2 is: "<<endl<<endl;;
    m3.show();
    cout<<"Matrix 4 is: "<<endl<<endl;;
    m4.show();
    cout<<"\n";
    if (m4==m2)
    {
        cout<<"Matrix 4 and matrix 2 are equal"<<endl<<endl;;
    }
    return 0;
}*/

// question 4

class Pairs
{
private:
    char numpair[20];
public:
    friend ostream &operator<<(ostream &output, const Pairs &p)
    {
        output << p.numpair;
        return output;
    }
    friend istream &operator>>(istream &input, Pairs &p)
    {
        char pair[20];
        input >> pair;
        int len = strlen(pair);
        if (len < 5 || pair[0] != '(' || pair[len - 1] != ')' || !strstr(pair, ","))
        {
            cout << "Invalid pair value found!" << endl;
            strcpy(p.numpair, "");
        }
        else
        {
            strcpy(p.numpair, pair);
        }
        return input;
    }
};

int main()
{
    Pairs p;
    cout << "Enter the value of pair object: ";
    cin >> p;
    cout << "Entered pair value is: " << p << endl;
    return 0;
}