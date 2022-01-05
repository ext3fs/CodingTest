//programmers 퍼즐조각채우기(84021)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Block{
	int cnt;
	vector<vector<int>> mat;
};

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

Block findBlock(vector<vector<int>>& vv, int x, int y, int val)
{
	vector<pair<int,int>> pos;
	queue<pair<int,int>> q;
	int n = vv.size();
	int maxX=x, minX=x, maxY=y, minY=y;

	vv[x][y] = !val;
	pos.push_back({x,y});	
	q.push({x,y});
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0; i<4; ++i)
		{
			int nx = x + dx[i]; 
			int ny = y + dy[i];

			if(nx<0 || nx==n || ny<0 || ny==n || vv[nx][ny] != val)
				continue;
			
			vv[nx][ny] = !val;
			pos.push_back({nx,ny});	
			q.push({nx,ny});

			maxX = max(maxX,nx);	
			minX = min(minX,nx);	
			maxY = max(maxY,ny);	
			minY = min(minY,ny);
		}
	}

	//cout << "cnt = " << pos.size() << endl;
	//cout << minX << "," << maxX << " : " << minY << "," << maxY << endl;

	vector<vector<int>> mat(maxX-minX+1, vector<int>(maxY-minY+1,!val));
	for(auto& p : pos)
		mat[p.first - minX][p.second - minY] = val;

	/*	
	for(int i=0; i<ret.size(); ++i)
	{
		for(int j=0; j<ret[0].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;	
	}*/

	return {pos.size(),mat};
}

bool isRight(Block& piece, Block& hole)
{
	if(hole.cnt == 0)
		return false;
	
	int row = piece.mat.size();
	int col = piece.mat[0].size();

	if(row != hole.mat.size() || col != hole.mat[0].size())
		return false;

	for(int i=0; i<row; ++i)
		for(int j=0; j<col; ++j)
			if(piece.mat[i][j] + hole.mat[i][j] != 1)
				return false;
	return true;
}

vector<vector<int>> rotate(vector<vector<int>>& v)
{
	int row = v.size();
	int col = v[0].size();
	vector<vector<int>> ret;

	for(int j=col-1; j>=0; --j)
	{
		vector<int> tmp;

		for(int i=0; i<row; ++i)
			tmp.push_back(v[i][j]);

		ret.push_back(move(tmp));
	}

	return ret;
}

int solution(vector<vector<int>> board, vector<vector<int>> table)
{
	int n = board.size(), ans=0;
	vector<Block> holes, pieces;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(board[i][j] == 0)
				holes.push_back(findBlock(board,i,j,0));

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(table[i][j] == 1)
				pieces.push_back(findBlock(table,i,j,1));

	for(auto& piece : pieces)
	{
		for(int i=0; i<4; ++i)
		{
			for(auto& hole : holes)
			{
				if(isRight(piece, hole))
				{
					ans += piece.cnt;
					hole.cnt = 0;
					piece.cnt = 0;
					break;
				}	
			}

			if(piece.cnt == 0)
				break;
			else	
				piece.mat = rotate(piece.mat);		
		}
	}	

	return ans;	
}

int main(void)
{
	vector<vector<int>> board
		= {{1,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,0,1},{1,1,0,1,1,1},{1,0,0,0,1,0},{0,1,1,1,0,0}};
	
	vector<vector<int>> table
		= {{1,0,0,1,1,0},{1,0,1,0,1,0},{0,1,1,0,1,1},{0,0,1,0,0,0},{1,1,0,1,1,0},{0,1,0,0,0,0}};

	int ans = solution(board,table);
	cout << "ans = " << ans << endl;	
	return	0;
}
