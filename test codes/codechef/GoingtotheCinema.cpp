#include<bits/stdc++.h>
using namespace std;

void test_case(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int answer=0;
    for (int i=-1;i<n;i++){
        int other_going=i;
        if(i==-1|| other_going>=a[i]){
            other_going=i+1;
            if(i==n-1|| other_going<a[i]){
                answer++;
            }
        }
    }
    cout<<answer<<"\n";
    }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        test_case();
    }
}