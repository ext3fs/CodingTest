//programmers 86052
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	bool visit[4];
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<string> g;	
vector<vector<Node>> vv;
int row, col;

int shot_ray(int dir, int x, int y)
{
	int cnt = 0;

	while(false == vv[x][y].visit[dir])
	{
		vv[x][y].visit[dir] = true;
		++cnt;
		x += dx[dir];
		y += dy[dir];

		if(x < 0)
			x = row -1;
		else if(x == row)
			x = 0;
		else if(y < 0)
			y = col -1;
		else if(y == col)
			y = 0;
				
		switch(g[x][y]){
			case 'L':
				dir = (++dir > 3) ? 0 : dir; 
				break;
			case 'R':
				dir = (--dir < 0) ? 3 : dir;
		}
	}
	return cnt;
}

vector<int> solution(vector<string> grid)
{
	vector<int> ans;
	int cnt;

	g = move(grid);	
	row = g.size();	
	col = g[0].size();
	vv.resize(row, vector<Node>(col));  
	
	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			for(int d=0; d<4; ++d)
				if((cnt = shot_ray(d,i,j)))
					ans.push_back(cnt);
	sort(ans.begin(), ans.end());
	return ans;
}

int main(void)
{
	vector<int> ans = solution({"SL","LR"});
	//vector<int> ans = solution({"R"});
	//vector<int> ans = solution({"R","R"});
	//vector<int> ans = solution({"SS"});
	int cnt = ans.size();

	for(int i=0; i<cnt; ++i)
		cout << ans[i] << " ";
	cout << endl;
	return	0;
}

