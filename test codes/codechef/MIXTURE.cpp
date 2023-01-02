#include<iostream>
using namespace std;

int main() {

    int mixture;
    cin>>mixture;
    while (mixture--){
        int x , y;
        cin>>x>>y;
        if(x==0) {
            cout<<"Liquid"<<endl;
        }
        else if(y==0){ 
            cout<<"Solid"<<endl;
        }
        else{
            cout<<"Solution"<<endl;
        }
    }
    return 0;
}