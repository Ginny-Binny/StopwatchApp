#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n , x, count;
    std::cin>>t;
    std::vector<int> arr;

    for(int i=0; i<t;i++){
        std::cin>>n;
        arr.reserve(n);
        count=0;

        for(int j=0;j<n;j++)
        {
            std::cin>>x;
            if(x%2==1){
                count++;

            }
            arr.push_back(x);
        }
        std::cout<<count/2<<"\n";
        count=0;
        arr.clear();
    }

    
return 0;
}