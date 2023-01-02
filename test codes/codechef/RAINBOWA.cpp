#include <iostream>
using namespace std;

int main() {
    
    int i , n , loop;
    cin>>loop;
    while(loop--)
    {
        cin>>n;
        int x[n];
        for(i=0;i<n;i++)
        {
            cin>>x[i];
        }
        int p=0,q=n-1,found=1;
        if(x[p]!=1){
            found=0;
        }
        else{
            while(p<q){
                if(x[p]!=x[q]){
                    found=0;
                    break;
                    
                }
                else if (x[p]!=x[p+1]&& x[p+1]!= x[p]+1){
                    found=0;
                    break;
                }
                p++;
                q--;
                
            }
        }
        
        if(x[p]!=7)
        found=0;
        
        if(found==1){
            cout<<"yes"<<endl;
        }
        else 
        cout<<"no"<<endl;
        
    }
	return 0;
}
