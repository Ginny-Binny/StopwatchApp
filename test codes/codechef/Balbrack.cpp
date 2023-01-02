#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n,a=0,b=0;
	    cin>>n;
	    string s;
	    cin>>s;
	    for(long long int i=0;i<n;i++)
	    {
	        if(s[i]=='(')
	        a++;
	        else b++;
	    }
	    long long int min;
	    min=a<b?a:b;
	    cout<<2*min<<endl;
	}
	return 0;
}