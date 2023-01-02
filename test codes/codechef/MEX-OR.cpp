#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key;
    cin>>key;
    while(key--){
        int num;
        cin>>num;
        if(num==0)
        {
        cout<<"1"<<endl;
        }
        else if(num==1 || num ==2){
            cout<<"2"<<endl;
        }
        else{
            int s=1;
            while(2*s <=num)
            s*=2;
            if(s==num){
                cout<<num<<endl;
            }
            else if(num ==(2*s-1)){
                cout<<num+1<<endl;
            }
            else {
                cout<<s<<endl;
            }
        }
    }
            return 0;

    }