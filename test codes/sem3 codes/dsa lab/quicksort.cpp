#include<iostream>
using namespace std;

void swap(float arr[], int i , int j){

    float temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

float partition( float arr[], int l , int r){

    float pivot=arr[r];
    float i=l-1;

    for(int j=l; j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr, i+1,r);
    return i+1;

}

void quickSort(float arr[] , int l , int r ) {


    if(l<r){

        float pi=partition(arr, l , r);
        quickSort(arr, l , pi-1);
        quickSort(arr, pi+1,r);
    }
}


int main(){
    
    float arr[5]={5.5,5.2,3.1,2.1,0.7};
    quickSort(arr,0,4);
    for(int i=4;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}