#include<iostream>
using namespace std;

int arr_input(int arr[], int elements) {
    cout<<"Enter the value of elements "<<endl;
    for (int i=0; i <elements ; i++ ) {
        cin>>arr[i];
    }
}

int display(int arr[] , int elements ) {
    for (int i =0 ; i < elements ; i++ ) {
        cout<<arr[i]<<" " ;
    }
}

int main() {
    int n, x , elements , end; 
    int arr[50];

    cout<<" Enter the number of elements you want to enter: ";
    cin>>elements;

    arr_input(arr, elements );
    cout<<"Elements in the array are: ";
    display(arr, elements);
    
    return 0;
}