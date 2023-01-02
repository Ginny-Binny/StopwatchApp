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

void deleteFromBinarySearch(int* arr, int size, int element){
    int index = binarySearch(arr, size, element); // taking index of the element to be deleted through binary search
    if(index == -1){
        cout<<"Element is not present!!";
        return;
    }
    for(int i = index; i<size-1; i++){
        arr[i] = arr[i+1];
    }
}

void insertFromBinarySearch(int* arr, int size, int element){
    binarySearch(arr, size, element);
    int index = pos_of_not_found; // finding the correct position of the element to be inserted through binary search
    for (int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}

int main(){
    int arr[20];
    int ele_toBeDelete, ele_toBeInsert, size = 10;
    cout<<"Enter 10 elements in the array"<<endl;
    for (int i = 0; i < 10; i++){
        cin>>arr[i];
    }
    printArray(arr, size);
    cout<<"Enter the element you wanted to delete: ";
    cin>>ele_toBeDelete;
    deleteFromBinarySearch(arr, size, ele_toBeDelete);
    size -= 1;
    printArray(arr, size);
    cout<<"Enter the element you wanted to insert: ";
    cin>>ele_toBeInsert;
    insertFromBinarySearch(arr, size, ele_toBeInsert);
    size += 1;
    printArray(arr, size);
    return 0;
}
