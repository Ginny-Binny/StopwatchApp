#include <bits/stdc++.h>
using namespace std;
void factor(int n){
    int t;
    cin>>t;
    for(int i=1; i<=t;i++){
       int j;
       j=0;
        if(t%i==0){
            cout<<i<<" ";
            j++;
        }
    }
}
int main(){
    int t,j;
     factor(t);
          cout<<j<<endl;

}
     