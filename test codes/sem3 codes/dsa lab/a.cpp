#include<iostream>
using namespace std;
void a_insert(int,int);
int arr[10] , n, num , pos ;
int main()
{
    int k;
    cout<<"enter the length of array ";
    cin>>n;
    cout<<"enter the digits in array";
    for(k=0; k<n; k++)
    {
        cin>>arr[k];
    }

    cout<<"enter element u wanna insert";
    cin>>num;
    cout<<"enter the position";
    cin>>pos;
    a_insert(num,pos);
    void a_insert(int num , int pos)
    {
        for (int i =5; i>-pos;i--)
        arr[i]=arr[i-1];
        arr[i]=num;
        n++;
    }
    cout<<arr[k];
    return 0;

}