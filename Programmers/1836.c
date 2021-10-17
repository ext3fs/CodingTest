//programmers 1836
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using tcii = tuple<char,int,int>;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

tcii findDelBlock(int m, int n, vector<string>& board, int a, int b)
{
	if(!isupper(board[a][b]))
		return {0,0,0};

	for(int i=0; i<4; ++i)
	{
		vector<pair<int,int>> v;
		int x = a;
		int y = b;

		while(1)
		{
			x += dx[i];
			y += dy[i];
		
			if(x<0 || x==m || y<0 || y==n)
				break;

			if(board[a][b] == board[x][y])
				return {board[a][b],x,y};

			if(board[x][y] != '.')
				break;

			v.push_back({x,y});
		}

		for(auto& pos : v)
		{
			int dir = (i+1)%4;
			x = pos.first;
			y = pos.second;

			while(board[x][y] == '.')
			{
				x += dx[dir]; 
				y += dy[dir];

				if(x<0 || x==m || y<0 || y==n)
					break;
					
				if(board[a][b] == board[x][y])
					return {board[a][b],x,y};
			}
		}
	}
	return {0,0,0};
}

string solution(int m, int n, vector<string> board)
{
	for(auto& s : board)
		cout << s << endl;

	int cnt = 0;
	for(auto& s : board)
		for(auto& c : s)
			if(isupper(c))
				++cnt;
				
	string ans = "";
	priority_queue<tcii,vector<tcii>,greater<tcii>> pq;
	tcii block;

	while(cnt)
	{
		for(int i=0; i<m; ++i)
		{	
			for(int j=0; j<n; ++j)
			{
				block = findDelBlock(m,n,board,i,j);
				
				if(get<0>(block) == 0)
					continue;

				pq.push({board[i][j],i,j});
				pq.push(block);
				board[i][j] = '#';
				board[get<1>(block)][get<2>(block)] = '#';
			}
		}

		if(pq.size() == 0)
			return "IMPOSSILBE";

		block = pq.top();
		pq.pop();
		board[get<1>(block)][get<2>(block)] = '.';

		block = pq.top();
		pq.pop();
		board[get<1>(block)][get<2>(block)] = '.';

		cnt -= 2;
		ans.push_back(get<0>(block));
	}
	return ans;
}

int main(void)
{
	vector<string> v = {"DBA", "C*A", "CDB"};
	string ret = solution(3,3,v);
	cout << "ret = " << ret << endl;
	return	0;
}
