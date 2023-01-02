#include <bits/stdc++.h>
using namespace std;

//1 max till ith term
/*int main(){
    int mx=-1999;
    int n;
    cout<<"enter the number if elements is the arry: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        mx=max(mx,a[i]);
        cout<<mx<<endl;
    }
    
return 0;
}*/

// number of subarrays = nC2 + n = n*(n+1)/2
// number subsequences 2^n

/* 2 problem: given an array a[] of size n output sum of each subarray od f the given arrya*/
// given 1,2,0,7,2
/*int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int curr=0;
    for (int i = 0; i < n; i++)
    {
        curr=0;
        for (int j = i; j < n; j++)
        {
           curr+=a[j];
           cout<<a[j];
        }
           cout<<" "<<curr;
           cout<<endl;
        
    }
    
    return 0;
}*/

// 3 to find maximum contigious arithmatic subarray 

/*int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int ans=2;
    int pd=a[1]-a[0];
    int j=2;
    int curr=2;
    while (j<n)
    {
        if (pd == a[j]-a[j-1])
        {
            curr++;
        }
        else{
            pd == a[j]-a[j-1];
            curr=2;
        }
        ans = max(ans,curr);
        j++;
    }
    cout<<ans<<endl;
    return 0;
}*/

// 4 for record braking day 
// satidfies the condition that number of the people in the park shoud be greater 
//than the previous as well as the following the

/*int main()
{
    int n;
    cin>>n;
    int a[n+1];
    a[n]=-1; // to satify the second condition
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    if(n=1){
        cout<<"1"<<endl;
        return 0;
    }

    int ans=0;
    int mx=-1;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>mx && a[i]>a[i+1])
        {
            ans++;
        }
        mx = max(mx,a[i]);
    }
    cout<<ans<<a[mx]<<endl;
    return 0;
}*/

