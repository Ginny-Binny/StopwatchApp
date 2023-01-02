#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int t;
  cin>>t;
  while(t--)
  {
      int n,b,c,i,k,j;
      cin>>n;
      int a[n];
      for(i=0;i<n;i++)
      {
          cin>>a[i];
      }
      k=0;
      for(j=1;j<n;j++)
      {
          if(a[j-1]%a[j]!=0)
          {
              k=1;
          }
      }
      if(k==0)
      {
          for(i=0;i<n;i++)
          {
              cout<<a[i]<<" ";
          }
          cout<<endl;
      }
      if(k==1)
      {
          cout<<-1<<endl;
      }
  }
  return 0;
}