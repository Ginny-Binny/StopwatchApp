#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD =  998244353;
#define rep(i,a,b) for(ll i=a;i<b;++i) 
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
#define int ll

const int MAX = 8e5+3;
int arr[MAX],lazy[MAX],tree[MAX],sub[MAX],in[MAX],out[MAX],cnt;
vector<int> adj[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = (arr[a]&1); // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}


void update_tree(int node, int a, int b, int i, int j) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] = b-a+1-tree[node]; // Update it

		if(a != b) 
        {
			lazy[node*2]^=1; // Mark child as lazy
    			lazy[node*2+1]^=1; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] = b-a+1-tree[node];

		if(a != b) { // Not leaf node
			lazy[node*2]^=1;
			lazy[node*2+1]^=1;
		}

        
    	return;
	}

	update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] = b-a+1-tree[node]; // Update it

		if(a != b) {
			lazy[node*2]^=1; // Mark child as lazy
			lazy[node*2+1]^=1; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = q1+q2; // Return final result
	
	return res;
}

void dfs(int node,int par)
{
    in[node]=cnt++;
    sub[node]=1;
    for(int i:adj[node])
    {
        if(i!=par)
        dfs(i,node),sub[node]+=sub[i];
    }
    out[node]=cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    rep(i,0,n)
    arr[i]=1;
    build_tree(1, 0, n-1);
    rep(i,0,n-1)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].emplace_back(y),adj[y].emplace_back(x);
    }
    dfs(0,0);
    int t;
    cin>>t;
    while(t--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            if(in[x]>in[y]) swap(x,y);
            ll b = query_tree(1, 0, n-1, in[y], out[y]-1);
            ll black = query_tree(1, 0, n-1, 0, n-1);
            cout<<b*(black-b)<<"\n";
        }
        else 
        {
            int x;
            cin>>x;
            x--;
            update_tree(1, 0, n-1, in[x], out[x]-1);
        }
    }
}