//backjun 1922
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;

int find_root(int node)
{
	if(node == parent[node])
		return node;	
	return parent[node] = find_root(parent[node]); 		
}

bool union_node(int a, int b)
{
	a = find_root(a);
	b = find_root(b);

	if(a == b)
		return false;

	if(a < b)
		parent[b] = a;
	else
		parent[a] = b;
	return true;	
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	int n,m,a,b,w,sum=0;
	cin >> n >> m;

	parent.resize(n+1);
	for(int i=1; i<=n; ++i)
		parent[i] = i;

	vector<tuple<int,int,int>> edge(m);
	for(int i=0; i<m; ++i){
		cin >> a >> b >> w;
		edge[i] = {w,a,b}; 	
	}
	sort(edge.begin(), edge.end());

	for(auto& e : edge)
	{
		w = get<0>(e);
		a = get<1>(e);
		b = get<2>(e);

		if(union_node(a,b))
		{
			sum += w;
			if(--n == 1)
				break;
		}
	}
	cout << sum << '\n';	
	return 0;
}
