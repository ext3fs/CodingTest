//backjun 1647
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> root;

int find_root(int node)
{
	if(root[node] == node)
		return node;	
	return root[node] = find_root(root[node]);
}

bool union_node(int a, int b)
{
	a = find_root(a);
	b = find_root(b);

	if(a == b)
		return false;

	if(a < b)
		root[b] = a;
	else	
		root[a] = b;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 

	int n,m,a,b,w,sum=0;
	
	cin >> n >> m;
	root.resize(n+1);
	for(int i=1; i<=n; ++i)
		root[i] = i;

	vector<tuple<int,int,int>> edge(m);
	for(int i=0; i<m; ++i){
		cin >> a >> b >> w;
		edge[i] = {w,a,b};			
	}
	sort(edge.begin(),edge.end());

	for(auto& e : edge)
	{
		if(union_node(get<1>(e),get<2>(e))){
			sum += get<0>(e);
			if(--n == 2)
				break;
		}		
	}
	cout << sum << '\n';			
	return 0;
}
