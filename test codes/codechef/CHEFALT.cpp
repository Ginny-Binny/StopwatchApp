#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,x=0,y=0,max=0;
	    cin>>n;
	    long long int a[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(i%2==0)
	        y+=a[i];
	        else x+=a[i];
	    }
	    max=x>y?x:y;
	    cout<<max<<endl;
	}
	return 0;
}