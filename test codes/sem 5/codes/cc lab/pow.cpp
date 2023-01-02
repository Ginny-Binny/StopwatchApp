#include<iostream>
using namespace std;

int power(int x,int n){
    if(n==0){
        return 1;
    }
    if(x==0 || x==1){
        return x;
    }
    else if(n%2==0){
        return power(x,n/2)*power(x,n/2);
    }
    else{
        return x*power(x,n/2)*power(x,n/2);
    }
}

int main(){
    int pow=power(2,5);
    cout<<pow<<endl;
    return 0;
}