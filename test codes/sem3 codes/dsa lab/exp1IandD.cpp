#include<iostream>
using namespace std;
void inputArray(int arr[], int elements)
{
    cout<<"Enter the value of the elements "<<endl;
    
    for(int i=0; i<elements; i++) {
        cin >>arr[i];
    }
}

void insertElement( int arr[], int elements , int x, int n)
{
    cout<<"Enter the value of the element you want to insert: "<<endl;
    cin>>n;

    cout<<"Enter the index:"<<endl;
    cin>>x;

    for( int i = elements -1 ; i >=x; i-- ) {
        arr[i+1]= arr[i];
    }

    arr[x]=n;

}

void deleteElement(int arr[], int elements , int n)
{
    cout<<"Enther the index of the element you want to delete :"<<endl;
    cin>>n;

    for(int i =n ; i< elements-1; i++) {
        arr[i]=arr[i+1];
    }
}

void display ( int arr[], int elements )
{
    for (int i=0; i<elements; i++) {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n,x , elements, end;
    int arr[100];
      
    cout<<" Enter the number of elements you want to enter: "<<endl;
    cin>>elements;

    inputArray(arr, elements);
    cout<<"Original array: ";
    display(arr,elements);
    cout<<endl;

    insertElement(arr, elements ,x , n);
    cout<<"Array after the insertion of value : ";
    elements = elements + 1;
    display(arr,elements);
    cout<<endl;

    deleteElement(arr, elements , n);
    cout<<"Array after the deletion of value: ";
    elements = elements -1;
    display( arr, elements);
    cout<<endl;

    return 0;
}







