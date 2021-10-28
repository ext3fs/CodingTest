//programmers 1829
#include	<iostream>
#include	<vector>
#include	<queue>

using	namespace	std;

int bfs(int x, int y, vector<vector<int>>& picture, vector<vector<int>>& visit)
{
	vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
	queue<pair<int, int>> q;
	int m = visit.size(), n = visit[0].size();
	int val = picture[x][y];
	int cnt = 1;

	visit[x][y] = 1;
	q.push(make_pair(x,y));

	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0; i<4; ++i)
		{
			int r = x + dir[i][0];
			int c = y + dir[i][1];

			if(r<0 || r==m || c<0 || c==n)
				continue;

			if(picture[r][c] == val && !visit[r][c])
			{
				++cnt;
				visit[r][c] = 1;
				q.push(make_pair(r,c));
			}
		}
	}

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	vector<vector<int>> visit(m,vector<int>(n,0));
	int area = 0, max_cnt = 0;

	for(int i=0; i<m; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			if(picture[i][j] && !visit[i][j])
			{
				++area;
				max_cnt = max(max_cnt, bfs(i, j, picture, visit));
			}
		}
	}

	vector<int> ret;
	ret.push_back(area);
	ret.push_back(max_cnt);
	return ret;
}

int	main(void)
{
	vector<vector<int>> pic = {{1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3}};	

	vector<int> v = solution(pic.size(), pic[0].size(), pic);	
	
	for(int val : v)
		cout << val << endl;

	return	0;
}

