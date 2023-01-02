#include <bits/stdc++.h>
#include<vector>
#include<unordered_set>
using namespace std;

void Distinct_element(vector<int> const &input, int k){
    for(int i=0;i<input.size()-(k-1);i++){
        unordered_set<int> distinct(input.begin()+i, input.begin()+i+k);

    cout<<"distinct elements are "<<i<<","<<(i+k-1)<<" is "<< distinct.size()<<endl;
}}
int main(){

    vector<int> input={5 ,8 ,5, 4, 4, 1};
    int k=3;
    Distinct_element(input,k);
     
return 0;
}