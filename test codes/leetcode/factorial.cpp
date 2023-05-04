#include<iostream>
using namespace std;

int factorial(int n){
    return(n==1||n==0)?1: n*factorial(n-1);
}

int main()
{
    int n=5;
    printf("fact is %d ", factorial(n));
    return 0;
}