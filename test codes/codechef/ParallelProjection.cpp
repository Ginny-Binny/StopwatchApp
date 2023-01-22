#include<bits/stdc++.h>
using namespace std;

void test_case(){
    int w,d,h;
    cin>>w>>d>>h;
    int a,b,f,g;
    cin>>a>>b>>f>>g;
    int answer=0;
    answer += h;
    swap(w,d);
    int tmp = min(a +f, d-a +d-f)+ abs(b-g);
    int tmp2 = min(b+g,w-b+w-g)+ abs(a-f);
    answer += min(tmp,tmp2);
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