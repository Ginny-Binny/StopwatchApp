#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,x;
        cin>>n>>l>>x;
        int slip=min(l,(n-l));
        cout<<x*slip<<endl;
    }
    return 0;
}