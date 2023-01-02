#include <iostream>
using namespace std;

int main() {
	int loop;
	int max;
	int count;
	int n;
	cin>>loop;
	while(loop--){
	    count=0;
	    max=-1;
	    cin>>n;
	    int arr[n];
	    for (int i = 0; i < n; i++) {
	        cin>>arr[i];
	    }
	    for (int i = 0; i < n; i++) {
	        if(arr[i]%2==0){
	            count++;
	            if(count>max)
	            max=count;
	        }
	        else{
	            count=0;
	        }
	        
	    }
	    std::cout << max << std::endl;
	}
	return 0;
}