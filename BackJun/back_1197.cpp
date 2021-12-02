//backjun - 최소스패닝트리(1197) 
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
	
	if(a < b)
		root[b] = a;
	else if(a > b)
		root[a] = b;
	else
		return false;	

	return true;
}

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int v, e;
	cin >> v >> e;
	
	root.resize(v+1);
	for(int i=0; i<=v; ++i)
		root[i] = i;

	int a, b, w;
	vector<tuple<int,int,int>> edges(e);	
	for(int i=0; i<e; ++i){
		cin >> a >> b >> w;
		edges[i] = {w,a,b};
	}	
	sort(edges.begin(), edges.end());

	int64_t sum = 0;
	for(const auto& edge : edges)
	{
		w = get<0>(edge);	
		a = get<1>(edge);	
		b = get<2>(edge);

		if(union_node(a, b)){
			sum += w;
			if(--v == 1)
				break;
		}
	}

	cout << sum << '\n';
	return 0;
}
