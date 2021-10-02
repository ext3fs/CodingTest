//programmers 42861
#include <iostream>
#include <vector>
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

bool comp(const vector<int>& v1, const vector<int>& v2)
{
	return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs)
{
	parent.resize(n);
	for(int i=0; i<n; ++i)
		parent[i] = i;

	sort(costs.begin(), costs.end(), comp);

	int sum = 0;
	for(auto& v : costs)
	{
		if(union_node(v[0], v[1]))
		{
			sum += v[2];
			if(--n == 1)
				break;
		}	
	}
	return sum;
}

int main(void)
{
	//vector<vector<int>> costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};
	vector<vector<int>> costs = {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}};
		
	int ans = solution(15, costs);
	cout << "ans = " << ans << endl;
	return	0;
}

