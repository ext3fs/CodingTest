#include	<iostream>
#include	<string>
#include	<list>
#include	<stack>

using	namespace	std;
	
int	input[5][2]	= {{5,4},{5,2},{1,2},{3,4},{3,1}};
int	max_node	= 5;
int	start		= 3;
int	**graph;

string	dfs(void)
{
	string		ret;
	int		visit[max_node+1] = {0,};
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

		//reverse search
		for(int i=max_node; i>0; --i)
			if(graph[node][i])
				stk.push(i);
	}
	return	ret;
}

string	bfs(void)
{
	string		ret;
	int			visit[max_node+1] = {0,};
	list<int>	ls;	

	visit[start]	= 1;
	ls.push_back(start);
	ret += to_string(start);

	while(!ls.empty())
	{
		int node	= ls.front();	
		ls.pop_front();	

		for(int i=0; i<=max_node; ++i)
		{
			if(visit[i] == 0 && graph[node][i] == 1){
				visit[i]	= 1;
				ls.push_back(i);
				ret += to_string(i);
			}
		}	
	}
	return	ret;
}

int	main(void)
{
	graph	= (int**)calloc(sizeof(int*), max_node+1);
	for(int i=0; i<=max_node; ++i)
		graph[i]	= (int*)calloc(sizeof(int), max_node+1);


	int a, b;		
	for(int i=0; i<5; ++i){
		a	= input[i][0];	
		b	= input[i][1];	
		graph[a][b]	= 1;	
		graph[b][a]	= 1;	
	}

	for(int i=0; i<=max_node; ++i){
		for(int j=0; j<=max_node; ++j)
			cout << graph[i][j] << " ";
		cout << endl;	
	}
	cout << dfs() << endl;
	cout << bfs() << endl;
		
	return	0;
}

