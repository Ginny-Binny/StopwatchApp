#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,total=0;
    cout<<"Enter the number of student: ";
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the marks of student "<<i+1<<": ";
        cin>>arr[i];
        total = total+ arr[i];
    }
    cout<<endl<<"The total is: "<<total;
return 0;
}

// question 2

/*class sample
{
public:
    sample(){cout << "constructor called" << endl;}
    ~sample(){cout<<"distructor called"<<endl;}
};
int main()
{
    int n;
    cin >> n;
    sample *arr = new sample[n];
    delete[] arr;
    return 0;
}*/
