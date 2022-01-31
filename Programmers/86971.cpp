//programmers 전력망을 둘로 나누기(86971)
#include <iostream>
#include <vector>
using namespace std;

/*
   * 트리구조에서 임의의 한노드에서 다른노드로 가는 경로는 유일하다
   1. 트리의 특성상 prev 노드만 체크하면 visit 체크가 된다
   2. 트리의 어느 노드를 root로 정해도 트리구조가 된다
   3. dfs()로 자식들의 수를 센다
   4. prev와 curr간의 경로를 없애고 남은 노드수 = child[idx] + 1이다 
*/

vector<int> child;

void dfs(vector<vector<int>>& adj, int curr, int prev)
{
	for(int next : adj[curr])
	{
		if(next == prev)
			continue;

		dfs(adj, next, curr);
		child[curr] += child[next] + 1;
	}
}

int solution(int n, vector<vector<int>> wires)
{
	vector<vector<int>> adj(n+1);
	for(auto& v : wires){
		adj[v[0]].push_back(v[1]);		
		adj[v[1]].push_back(v[0]);		
	}

	child.assign(n+1,0);
	dfs(adj, 1, 0);

	int ans = n;
	for(int i : child){
		int a = i + 1;
		int b = n - a;
		ans = min(ans, abs(a-b));
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
