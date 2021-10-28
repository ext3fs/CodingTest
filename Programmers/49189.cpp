//programmers 49189
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int n, vector<vector<int>>& adj)
{
	vector<int> visit(n+1); 
	queue<pair<int,int>> q;
	int max_walk=1, cnt=0;
	
	q.push({1,1});
	visit[1] = 1;

	while(!q.empty())
	{
		int node = q.front().first;
		int walk = q.front().second;
		q.pop();

		for(int idx : adj[node])
		{
			if(visit[idx])
				continue;

			q.push({idx,walk+1});	
			visit[idx] = walk+1;
			max_walk = walk+1;
		}
	}

	for(int val : visit)
		if(val == max_walk)
			++cnt;
	return cnt;
}


int solution(int n, vector<vector<int>> edge)
{
	vector<vector<int>> adj(n+1);

	for(size_t i=0; i<edge.size(); ++i){
		int a = edge[i][0];
		int b = edge[i][1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	return bfs(n,adj);
}

int main(void)
{
	vector<vector<int>> v = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
	int ret = solution(6,v);
	cout << "ret = " << ret << endl;
	return	0;
}


