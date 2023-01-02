#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, train, eq, p_bus;
    cin>>t;
    while(t--){
        cin>>train>>eq>>p_bus;
        if(train+eq>p_bus){
            cout<<"Train"<<endl;
        }
        else if(train+eq==p_bus){
            cout<<"EQUAL"<<endl;
        }
        else cout<<"PLANEBUS"<<endl;
    }
return 0;
}