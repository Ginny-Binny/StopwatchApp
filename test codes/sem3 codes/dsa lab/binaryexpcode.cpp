#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int pos_of_not_found; // global variable to store the position of the element so that to insert the element in the array no matter same element exists or not

void printArray(int* arr, int size){
    cout<<"Printing the array"<<endl;
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int binarySearch(int* arr, int size, int element){
    int mid, low, high;
    low = 0;
    high = size-1;
    // int found = -1;
    while (low<=high){
        mid = (low+high)/2;
        if(arr[mid] == element){
            pos_of_not_found = mid; // storing the position inside the global variable
            return mid;
        }
        else if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    pos_of_not_found = mid+1;
    return -1;
}

int main(){
    int arr[20];
    int ele_toBeSearch, size = 10;
    cout<<"Enter 10 elements in the array"<<endl;
    for (int i = 0; i < 10; i++){
        cin>>arr[i];
    }
    printArray(arr, size);
    cout<<"Enter the element you wanted to search: ";
    cin>>ele_toBeSearch;
    int res = binarySearch(arr,size,ele_toBeSearch);
    if (res!=-1){
        cout<<"Element present at the index: "<<binarySearch(arr,size,ele_toBeSearch);
    }
    else{
        cout<<"Position of the element if it was present: "<<pos_of_not_found;
    }
    
return 0;
}
