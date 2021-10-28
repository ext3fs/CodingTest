#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using p = pair<int,int>;

vector<vector<p>> mat;
vector<int> dist;

int dijkstra(int start,int end)
{
	priority_queue<p,vector<p>,greater<p>> q;

	dist[start] = 0;
	q.push(make_pair(0,start));

	while(!q.empty())
	{
		int curr_cost = q.top().first;
		int curr = q.top().second;
		q.pop();

		if(curr == end)
			return curr_cost;

		if(dist[curr] < curr_cost)
			continue;

		for(auto& e : mat[curr])
		{
			int next_cost = e.first + curr_cost;
			int next = e.second;
			
			if(dist[next] > next_cost){
				dist[next] = next_cost;
				q.push(make_pair(next_cost,next));				
			}
		}	
	}
	return -1;
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n,m,x,y,w,start,end;
	
	cin >> n >> m;
	mat.resize(n+1);
	dist.resize(n+1,2e9);
	for(int i=0; i<m; ++i){
		cin >> x >> y >> w;
		mat[x].push_back(make_pair(w,y));		
	}	
	cin >> start >> end;
	
	cout << dijkstra(start,end) << endl;
	return 0;
}
