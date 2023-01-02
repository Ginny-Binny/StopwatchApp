#include <bits/stdc++.h> 
using namespace std; 
  
void intTobinary(int num) 
{ 
    int b_Num[100]; 
  
    int a = 0; 
    while (num > 0) { 
  
        b_Num[a] = num % 2; 
        num = num / 2; 
        a++; 
    } 
  
    for (int b = a - 1; b >= 0; b--) 
        cout << b_Num[b]; 
} 
  
int main() 
{ 
    int num = 55; 
    intTobinary(num); 
    return 0; 
} 