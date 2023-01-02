#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
const int M = 1e6-1;
int rt[M];
const int nodes = 4, edges = 5;
pair <long long, pair<int, int> > p[M];


int par(int a) 
{
 while(rt[a] != a)
 {
 rt[a] = rt[rt[a]];
 a = rt[a];
 }
 return a;
}


void findUnion(int a, int b) 
{
 int d = par(a);
 int e = par(b);
 rt[d] = rt[e];
}


long long kruskal()
{
 int a, b;
 long long cost, min_cost = 0;
 for(int i = 0 ; i < edges ; ++i)
 {
 a = p[i].second.first;
 b = p[i].second.second;
 cost = p[i].first;
 if(par(a) != par(b)) 
 {
 min_cost += cost;
 findUnion(a, b);
 }
 }
 return min_cost;
}


int main()
{
 int x, y;
 long long weight, cost, min_cost;
 for(int i = 0;i < M;++i) 
 {
 rt[i] = i;
 }
 p[0] = make_pair(10, make_pair(0, 1));
 p[1] = make_pair(11, make_pair(1, 2));
 p[2] = make_pair(12, make_pair(2, 3));
 p[3] = make_pair(14, make_pair(0, 2));
 p[4] = make_pair(17, make_pair(1, 3));
 sort(p, p + edges); 
 
 min_cost = kruskal();
 cout << "Minimum cost: "<< min_cost << endl;
 return 0;
}