//backjun 1260
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, m, v, a, b;

void dfs(vector<vector<int>>& adj)
{
	stack<int> stk;
	vector<bool> visit(n+1);

	stk.push(v);
	
	while(!stk.empty())
	{
		int node = stk.top(); stk.pop();
		
		if(visit[node])
			continue;
		
		visit[node] = true;
		printf("%d ", node);

		//reverse
		for(int i=adj[node].size()-1; i>=0; --i)
			stk.push(adj[node][i]);
	}
	printf("\n");		
}

void bfs(vector<vector<int>>& adj)
{
	queue<int> q;
	vector<bool> visit(n+1);

	q.push(v);

	while(!q.empty())
	{
		int node = q.front(); q.pop();

		if(visit[node])
			continue;

		visit[node] = true;
		printf("%d ", node);

		for(int val : adj[node])
			q.push(val);		
	}
	printf("\n");		
}

int main(void)
{
	scanf("%d%d%d", &n, &m, &v);

	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; ++i)
	{
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);	
		adj[b].push_back(a);	
	}

	for(int i=1; i<=n; ++i)
		sort(adj[i].begin(), adj[i].end());

	dfs(adj);
	bfs(adj);
	return 0;
}

