// #include<bits/stdc++.h>
// using namespace std;

// int solver(vector<int>& arr, int n){
//     int sum = 0;
//     int rem1=0, rem2=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]%3 == 1)   rem1++;
//         if(arr[i]%3 == 2)   rem2++;
//         sum += arr[i];
//     }
//     if(sum % 3 != 0)    return -1;
//     if(rem1 == rem2)    return rem1;
//     return (rem1+rem2)/2;
// }


// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int>arr(n);
//         for(int i=0; i<n; i++){
//             cin >> arr[i];
//         }
//         cout << solver(arr, n)<<endl;
//     }
//     return 0;
// }


