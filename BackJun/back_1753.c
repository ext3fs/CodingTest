//backjun 1753(최단경로) 
#include <iostream>
#include <vector>
#include <queue>

using	namespace	std;
using	p = pair<int,int>; 

vector<vector<p>> mat;
vector<int> dist;

void dijkstra(int start)
{
	priority_queue<p, vector<p>, greater<p>> q;

	dist[start] = 0;
	q.push(make_pair(0,start));

	while(!q.empty())
	{
		int curr_cost = q.top().first;
		int curr = q.top().second;
		q.pop();

		if(dist[curr] < curr_cost)
			continue;
		
		for(auto& m : mat[curr])
		{
			int next_cost = m.first + curr_cost;
			int next = m.second;
			
			if(dist[next] > next_cost){
				dist[next] = next_cost;
				q.push(make_pair(next_cost,next));	
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

	mat.resize(v+1);
	dist.resize(v+1, 2e9);
	
	for(int i=0; i<e; ++i){
		int x,y,cost;
		cin >> x >> y >> cost;
		mat[x].push_back(make_pair(cost,y));	
	}

	dijkstra(start);

	for(int i=1; i<=v; ++i)
	{
		if(dist[i] == 2e9)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
	return	0;
}

