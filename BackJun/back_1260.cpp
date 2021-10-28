//backjun 1260
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using	namespace	std;

string	dfs(vector<vector<int>>& map, int max_node, int start)
{
	string		ret;
	int			visit[max_node+1] = {0,};
	stack<int>	stk;

	stk.push(start);

	while(!stk.empty())
	{
		int	node	= stk.top();
		stk.pop();

		if(visit[node])
			continue;

		visit[node]	= 1;	
		ret += to_string(node);

		sort(map[node].begin(), map[node].end(), greater<int>());
		for(size_t i=0; i<map[node].size(); ++i)
			stk.push(map[node][i]);
	}
	return	ret;
}

string	bfs(vector<vector<int>>& map, int max_node, int start)
{
	string		ret;
	int			visit[max_node+1] = {0,};
	list<int>	ls;	

	ls.push_back(start);

	while(!ls.empty())
	{
		int node	= ls.front();	
		ls.pop_front();	
		
		if(visit[node])
			continue;
			
		visit[node]	= 1;
		ret += to_string(node);

		sort(map[node].begin(), map[node].end());
		for(size_t i=0; i<map[node].size(); ++i)
			ls.push_back(map[node][i]);
	}
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int	max_node, line, start;
	cin >> max_node >> line >> start;
	
	int	a,b;
	vector<vector<int>>	map(max_node+1,vector<int>(0));
	
	for(int	i=0; i<line; ++i){
		cin >> a >> b; 
		map[a].push_back(b);	
		map[b].push_back(a);	
	}

	for(size_t i=0; i<map.size(); ++i){
		for(size_t j=0; j<map[i].size(); ++j)
			cout << map[i][j] << " "; 
		cout << endl;	
	}

	cout << dfs(map, max_node, start) << "\n";
	cout << bfs(map, max_node, start) << "\n";
	return	0;
}

