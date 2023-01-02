#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

void solution(int b[], int n, int result[] ){
    
    priority_queue<p,vector<p>,greater<p> > q;
    p temp;
    for(int i=0;i<n;i++){
        temp.first=b[i],temp.second=i;
        q.push(temp);
    }

    int prev_value=-1;
    while(!q.empty()){
        if(prev_value+1<q.top().first){
            result[q.top().second]=prev_value+1;
            prev_value++;
        }
        else{
            result[q.top().second]=prev_value;
        }
        q.pop();
    }
}

int main()
{
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int result[n];
        solution(b,n,result);
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}