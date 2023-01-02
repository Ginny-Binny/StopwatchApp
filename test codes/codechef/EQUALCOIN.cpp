#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long int x, y;
        cin>>x>>y;

        if(x%2==1)
        cout<<"NO \n"; 
        else if(x%2==0 && y%2==0)
        cout<<"YES \n";
        else if(x>1)
        cout<<"YES\n";
        else 
        cout<<"NO\n";

    } 
return 0;
}