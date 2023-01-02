#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,a,b,count=0;
	    cin>>n>>a>>b;
	    long long int q[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>q[i];
	        if(q[i]<=a && (q[i]%b)==0)
	        count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}