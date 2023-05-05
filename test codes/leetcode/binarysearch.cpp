#include<iostream>
using namespace std;


int binarysearch(int arr[], int n, int key){
    int s=0;
    int e=n;
    if(s<=e){
        int mid= s+(e-s)/2;

        if(arr[mid]==key)
        return mid;

        if(arr[mid]>key)
            return binarysearch(arr, s, mid-s, key);
        

        return binarysearch(arr, mid+1,s,key);
    }

    return -1;
        
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int key;
    cin>>key;
}