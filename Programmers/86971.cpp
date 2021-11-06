//programmers 전력망을 둘로 나누기(86971)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/*
   * 트리구조에서 임의의 한노드에서 다른노드로 가는 경로는 유일하다
   1. n의 갯수는 100이하 -> 완전탐색 가능
   2. 간선 하나를 끊고 임의의 노드에서 가능한 모든 노드 탐색 -> O(2*E)보다 작다
   3. 모든 간선에 대해 3 실행 -> O(V*E)  
*/

int bfs(int n, vector<unordered_set<int>>& adj)
{
	queue<int> q;
	vector<bool> visit(n+1);
	int cnt = 0;

	q.push(1);
	visit[1] = true;
	++cnt;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int node : adj[curr])
		{
			if(visit[node])
				continue;
			
			q.push(node);
			visit[node] = true;
			++cnt;	
		}
	}
	return abs((n - cnt) - cnt);	
}

int solution(int n, vector<vector<int>> wires)
{
	vector<unordered_set<int>> adj(n+1);
	for(auto& v : wires){
		adj[v[0]].insert(v[1]);		
		adj[v[1]].insert(v[0]);		
	}

	int ans = 2e9;
	for(auto& v : wires)
	{
		adj[v[0]].erase(v[1]);		
		adj[v[1]].erase(v[0]);		
		
		ans = min(ans, bfs(n,adj));

		adj[v[0]].insert(v[1]);		
		adj[v[1]].insert(v[0]);		
	}
	return ans;
}

int main(void)
{
	vector<vector<int>> v = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
	int ans = solution(9,v);
	cout << "ans = " << ans << endl;
	return	0;
}
