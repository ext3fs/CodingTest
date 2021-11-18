//programmers 자물쇠와 열쇠(60059)
#include <iostream>
#include <vector>
using namespace std;

int n, m;

bool isFit(int bi, int bj, vector<vector<int>> board, vector<vector<int>>& key)
{
	for(int i=0; i<m; ++i)
		for(int j=0; j<m; ++j)
			board[bi+i][bj+j] += key[i][j];

	for(int i=n; i<n+n; ++i)
		for(int j=n; j<n+n; ++j)
			if(board[i][j] != 1)
				return false;
	return true;		
}

vector<vector<int>> rotateKey(vector<vector<int>>& key)
{
	vector<vector<int>> tmp(m);

	for(int j=0; j<m; ++j)
		for(int i=m-1; i>=0; --i)
			tmp[j].push_back(key[i][j]);
	return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	n = lock.size();
	m = key.size();
	vector<vector<int>> board(n*3,vector<int>(n*3));

	for(int i=n; i<n+n; ++i)
		for(int j=n; j<n+n; ++j)
			board[i][j] = lock[i-n][j-n];		

	for(int i=0; i<4; ++i)
	{
		for(int i=0; i<n+n; ++i)
			for(int j=0; j<n+n; ++j)
				if(isFit(i,j,board,key))
					return true;

		key = rotateKey(key);
	}

	return false;
}

int main(void)
{
	vector<vector<int>> k = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
	vector<vector<int>> l = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

	bool ans = solution(k,l);
	cout << "ans = " << ans << endl;
	return	0;
}
