//backjun 1753(최단경로) 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int,int>; 

vector<vector<pii>> adj;
vector<int> cost;

void dijkstra(int start)
{
	priority_queue<pii, vector<pii>, greater<pii>> q;

	cost[start] = 0;
	q.push({0,start});

	while(!q.empty())
	{
		int curr_cost = q.top().first;
		int curr = q.top().second;
		q.pop();

		if(cost[curr] < curr_cost)
			continue;
		
		for(auto& p : adj[curr])
		{
			int next_cost = p.first + curr_cost;
			int next = p.second;
			
			if(cost[next] > next_cost){
				cost[next] = next_cost;
				q.push({next_cost,next});	
			}	
		}	
	}	
}

int	main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v,e,start;
	cin >> v >> e;
	cin >> start;

	adj.resize(v+1);
	cost.resize(v+1, 1e9);
	
	for(int i=0; i<e; ++i){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back({w,y});	
	}

	dijkstra(start);

	for(int i=1; i<=v; ++i)
	{
		if(cost[i] == 1e9)
			cout << "INF\n";
		else
			cout << cost[i] << '\n';
	}
	return	0;
}

