//backjun 3665
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topology_sort()
{
	int n,m,a,b;
	cin >> n;
	
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i];

	vector<int> degree(n+1);	
	vector<vector<bool>> mat(n+1,vector<bool>(n+1,false));
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n; ++j){
			mat[v[i]][v[j]] = true;
			++degree[v[j]];
		}		
	}
	
	cin >> m;
	for(int i=0; i<m; ++i)
	{
		cin >> a >> b;

		if(mat[a][b]){
			mat[a][b] = false;	
			mat[b][a] = true;	
			--degree[b];
			++degree[a];
			continue;
		}

		mat[a][b] = true;	
		mat[b][a] = false;	
		--degree[a];
		++degree[b];
	}

	queue<int> q;
	for(int i=1; i<=n; ++i)
		if(degree[i] == 0)
			q.push(i);

	bool many = false; 		
	vector<int> ret;
	while(!q.empty())
	{
		if(q.size() != 1){
			many = true;
			break;
		}

		int node = q.front();
		q.pop();
		ret.push_back(node);

		for(int i=1; i<=n; ++i)
			if(mat[node][i] && --degree[i] == 0)
				q.push(i);
	}

	if(many)
		cout << "?";
	else if(ret.size() != (size_t)n)
		cout << "IMPOSSIBLE";
	else	
		for(auto e : ret)
			cout << e << ' ';
	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 

	int team;
	cin >> team;

	while(team--)
		topology_sort();		
	return 0;
}
