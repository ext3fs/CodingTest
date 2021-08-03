//programmers 12978
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

vector<vector<pair<int,int>>> graph; 	
vector<int> dist;

void dijkstra(int start)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	
	dist[start] = 0;
	q.push(make_pair(0, start));

	while(!q.empty())
	{
		int curr = q.top().second;
		int curr_cost = q.top().first;		
		q.pop();

		if(dist[curr] < curr_cost)
			continue;

		for(auto& e : graph[curr])
		{
			int next = e.second;
			int next_cost = e.first + curr_cost;

			if(dist[next] > next_cost){
				dist[next] = next_cost;
				q.push(make_pair(next_cost,next));
			}		
		}
	}	
}

int solution(int n, vector<vector<int>> road, int k)
{
	graph.resize(n+1);
	dist.resize(n+1, INT_MAX);

	for(auto& e : road){
		int x = e[0], y = e[1], cost = e[2];
		graph[x].push_back(make_pair(cost,y));
		graph[y].push_back(make_pair(cost,x));
	}

	dijkstra(1);

	int ret = 0;
	for(auto& e : dist)
		if(e <= k)
			++ret;
	return ret;	
}

int	main(void)
{
	//vector<vector<int>> v = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
	vector<vector<int>> v = {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
	cout << solution(6,v,4) << endl;
	return	0;
}

