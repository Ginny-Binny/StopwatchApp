#include <bits/stdc++.h>
using namespace std;
int main() {
     int t;
     cin>>t;
      while(t--){
           int n;
           cin>>n;
            string s;
            cin>>s;
             int w=0,b=0;
              char prev=s[0];
               if(prev=='W')
               w++;
                else 
                b++; 
                for(int i=1; i<n; i++){
                     if(prev==s[i])
                     {
                          continue;
                           }
             else{
                if(s[i]=='B')
                b++; 
                else
                 w++;
                  } 
            prev=s[i];
             }
        cout<<min(w,b)<<endl; 
        }
         return 0;
         }