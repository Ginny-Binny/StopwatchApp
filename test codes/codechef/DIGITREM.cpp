#include<bits/stdc++.h>
using namespace std;

int main()
{
    int key;
    cin>>key;
    while(key--){

        int num ,dig;
        cin>>num>>dig;
        int New=num, rem, a=0, c=0;
        while(New >0){
            rem=New %10;
            New = New /10;
            c++;
            if (rem == dig){
                New = New * pow(10,c) + (rem +1) * pow(10,c-1);
                a = New -num;
                c=0;
            }

        }

        cout<<a<<endl;
    }
    return 0;
}