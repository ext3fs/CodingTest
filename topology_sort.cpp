//backjun 2252
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> indegree;
vector<vector<int>> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 

	int n,m,a,b;
	cin >> n >> m;

	indegree.resize(n+1,0);
	v.resize(n+1);
	for(int i=0; i<m; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		++indegree[b];	
	}

	queue<int> q;
	for(int i=1; i<=n; ++i)
		if(indegree[i] == 0)
			q.push(i);
		
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << ' ';
		
		for(auto& e : v[node])
		{
			if(--indegree[e] == 0)
				q.push(e);	
		}
	}	
	cout << '\n';
	return 0;
}
