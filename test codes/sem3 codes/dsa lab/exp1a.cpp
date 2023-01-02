#include<iostream>
using namespace std;
int main()
{
    int arr[5] , new , i;
    cout<<"Enter the 4 array elements of the array \n ";
    for(i=0; i<4; i++)
    cin>>arr[i];
    cout<<"Enter the element to be inserted ";
    cin>>new;
    arr[i]=new;
    cout<<"\n The new array is : \n";
    for(i=0; i <5; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}