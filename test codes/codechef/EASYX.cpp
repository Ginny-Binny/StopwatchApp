#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define endl			"\n"
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define get(t)          ll t; cin >> t; while(t--)



void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}


void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif
}

    bool sieve[10000005];
    void createSieve(){
        
        for( int i=2; i<=10000000; i++){
            
            sieve[i] = true;
        }
        
        for(int i=2; i*i<=10000000; i++){
            
            if( sieve[i] == true){
                
                for(int j=i*i; j<=10000000; j+=i){
                    
                    sieve[j] = false;
                }
            }
        }
    }

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	createSieve();
	get(t){

		ll n,prod = 1;
		cin >> n;

		vector<ll>arr;

		for(int i=0; i<n; i++){
			ll x;
			cin >> x;
			arr.push_back(x);
			prod *= arr[i];
		}
		ll ans = 0;
		// cout << prod << " ";

		for(int i=2; i<=10000000; i++){

			if(sieve[i] == true){

				if(prod%i != 0){

					ans = i;
					break;
				}
			}
		}
		cout << ans << endl;
	}



	#ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 

	return 0;
}