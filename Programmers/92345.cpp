//programmers 사라지는발판(92345)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int row, col;
vector<vector<int>> bo;

pair<bool,int> bDfs(int aRow, int aCol, int bRow, int bCol);

pair<bool,int> aDfs(int aRow, int aCol, int bRow, int bCol)
{
	if(bo[aRow][aCol] == 0)
		return {false,0};

	set<int> aWin, aLose;
	for(int i=0; i<4; ++i)
	{
		int x = dx[i] + aRow;
		int y = dy[i] + aCol;

		if(x<0 || x==row || y<0 || y==col || bo[x][y] == 0)
			continue;
		
		bo[aRow][aCol] = 0; 
		auto p = bDfs(x,y,bRow,bCol);
		if(p.first)
			aWin.insert(p.second);
		else
			aLose.insert(p.second);
		bo[aRow][aCol] = 1; 
	}

	if(aWin.size())
		return {true,*aWin.begin()+1};
	if(aLose.size())
		return {false,*aLose.rbegin()+1};
	return {false,0};
}

pair<bool,int> bDfs(int aRow, int aCol, int bRow, int bCol)
{
	if(bo[bRow][bCol] == 0)
		return {true,0};

	set<int> aWin, aLose;
	for(int i=0; i<4; ++i)
	{
		int x = dx[i] + bRow;
		int y = dy[i] + bCol;

		if(x<0 || x==row || y<0 || y==col || bo[x][y] == 0)
			continue;
		
		bo[bRow][bCol] = 0; 
		auto p = aDfs(aRow,aCol,x,y);
		if(p.first)
			aWin.insert(p.second);
		else
			aLose.insert(p.second);
		bo[bRow][bCol] = 1; 
	}

	if(aLose.size())
		return {false,*aLose.begin()+1};
	if(aWin.size())
		return {true,*aWin.rbegin()+1};
	return {true,0};
}

int solution(vector<vector<int>> board, vector<int> a, vector<int> b)
{
	bo = move(board);
	row = bo.size();
	col = bo[0].size();
	return aDfs(a[0],a[1],b[0],b[1]).second;
}

int main(void)
{
	vector<vector<int>> v = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
	vector<int> a = {1,0};
	vector<int> b = {1,2};
	/*
	vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	vector<int> a = {1,0};
	vector<int> b = {1,2};
	vector<vector<int>> v = {{1,1,1,1,1}};
	vector<int> a = {0,0};
	vector<int> b = {0,4};
	vector<vector<int>> v = {{1}};
	vector<int> a = {0,0};
	vector<int> b = {0,0};
	*/

	int ans = solution(v,a,b);
	cout << "ans = " << ans << endl;
	return	0;
}
