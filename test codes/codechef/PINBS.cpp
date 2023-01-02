#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    string res = "No\n";
    for (int i = 0; i < s.length()-1; i++)
    {
        if((s[i] == '1' && s[i+1] == '1') || (s[i] == '1' && s[i+1] == '0')){
            res = "Yes\n";
            break;
        }
    }
    cout<<res;
    }
return 0;
}


//  #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
        
//         int n=s.length();
//         if(n==1){
//             cout<<"No\n";
//             continue;

//         }
//         int count=0, p=-1;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1')
//             {
//             count++;
//              p=i+1;}

//         }
        
//     } 
//     if(count==0||(count==1&& p==n)) cout<<"No\n";
//     else 
//     cout<<"Yes\n";}
// return 0;
// }