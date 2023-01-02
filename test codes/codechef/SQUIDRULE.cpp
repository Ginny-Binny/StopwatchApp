#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t; 
    while(t--){
        int n , i , j,k, w_c=0,b_c=0;
        int x,y;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int prize=0;
        for(i=1;i<n;i++){
            prize+=arr[i];
        }
        cout<<prize<<endl;
    }
return 0;
}