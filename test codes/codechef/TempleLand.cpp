#include <iostream>
using namespace std;

int main() 
{
	int s,n,flag,i;
	cin>>s;
	 while(s--)
	  {
	       flag=0;
	       cin>>n;
	       int arr[n];
	        for(i=0;i<n;i++)
	         cin>>arr[i];
	        if(n%2!=0 && arr[0]==1 && arr[n-1]==1) 
	         {
	          for(i=0;i<n/2;)
	           {
	             if(arr[i+1]==arr[i]+1)
	              i++;
	             else
	              {
	                  flag=1;
	                  break;
	              }       
	           }
	          
	          if(flag==0)
	           {
	              for(i=n/2+1;i<n-1;)
	               {
	                   
	                   if(arr[i]==arr[i+1]+1)
	                    i++;
	                   else
	                    {
	                        flag=1;
	                        break;
	                    }
	               }
	            }
	           
	          if(flag==1)
	           cout<<"no";
	          else
	           cout<<"yes";
	           
	    }
	    
	        else
	         cout<<"no";
	         
	        cout<<endl; 
	  }
	return 0;
}
