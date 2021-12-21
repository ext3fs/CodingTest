//programmers 합승택시요금(72413)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int,int>;

vector<int> dij(vector<vector<pii>>& adj, int start)
{
	vector<int> cost(adj.size(), 7e8);
	priority_queue<pii, vector<pii>, greater<pii>> q;	

	cost[start] = 0;
	q.push({0,start});	

	while(!q.empty())
	{
		int currCost = q.top().first;				
		int curr = q.top().second;
		q.pop();

		if(cost[curr] < currCost)
			continue;

		for(auto& v : adj[curr])
		{
			int next = v.first;				
			int nextCost = v.second + currCost;

			if(cost[next] > nextCost){
				cost[next] = nextCost;
			       	q.push({nextCost,next});
			}	
		}
	}

	return cost; 
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	vector<vector<pii>> adj(n+1);
	for(auto& v : fares){
		adj[v[0]].push_back({v[1],v[2]});
		adj[v[1]].push_back({v[0],v[2]});
	}
	
	vector<int> sCost = dij(adj,s);
	vector<int> aCost = dij(adj,a);
	vector<int> bCost = dij(adj,b);

	int ans = INT32_MAX;
	for(int i=1; i<=n; ++i)
		ans = min(ans, sCost[i] + aCost[i] + bCost[i]);
	return ans;	
}

int main(void)
{
	int n = 6; 
	int s = 4; 
	int a = 6; 
	int b = 2; 
	vector<vector<int>> v = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41},
					{5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
	int ans = solution(n,s,a,b,v);
	cout << ans << endl;	
	return	0;
}
