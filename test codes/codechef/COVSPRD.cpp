#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--){
    int N,D;
	int q=1;

	cin>>N>>D;
	if(D<=10)
	{
	    int q=pow(2,D);
        if(q<=N)
        cout<<q<<endl;
	
    else 
    cout<<N;

    }
    else if( D>10 && D<=20)
{    long long int q=1024*pow(3,(D-10));
    if(q<=N)
    cout<<q<<endl;
    else
    cout<<N<<endl;
    }

    else 
    cout<<N<<endl;

    
    }
	return 0;
}