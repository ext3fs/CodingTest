//programmers 사라지는발판(92345)
#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int ans, aMinMove, bMinMove, row, col;
vector<vector<int>> bo;

void bDfs(vector<int> a, int aMove, vector<int> b, int bMove);

void aDfs(vector<int> a, int aMove, vector<int> b, int bMove)
{
	cout << "aDfs : " << aMove << "," << bMove << endl;
	for(auto& v : bo){
		for(int i : v)
			cout << i << " ";
		cout << endl;
	}

	//b win
	//if(cnt == 0){
	if(bo[a[0]][a[1]] == 0){

		cout << "b win : " << bMinMove << "," << aMove << "," << bMove << endl;
		bMinMove = min(bMinMove, bMove);
		if(bMove == bMinMove)
			ans = max(ans, aMove + bMove);
	}

	int cnt = 0;

	for(int i=0; i<4; ++i)
	{
		int x = dx[i] + a[0];
		int y = dy[i] + a[1];

		if(x<0 || x==row || y<0 || y==col || bo[x][y] == 0)
			continue;
		++cnt;
		bo[a[0]][a[1]] = 0; 
		bDfs({x,y}, aMove+1, b, bMove);
		bo[a[0]][a[1]] = 1; 
	}

}

void bDfs(vector<int> a, int aMove, vector<int> b, int bMove)
{
	cout << "bDfs : " << aMove << "," << bMove << endl;
	for(auto& v : bo){
		for(int i : v)
			cout << i << " ";
		cout << endl;
	}

	int cnt = 0;

	//a win
	//if(cnt == 0){
	if(bo[b[0]][b[1]] == 0){
		cout << "a win : " << aMinMove << "," << aMove << "," << bMove << endl;
		aMinMove = min(aMinMove, aMove);
		if(aMove == aMinMove)
			ans = max(ans, aMove + bMove);
	}

	for(int i=0; i<4; ++i)
	{
		int x = dx[i] + b[0];
		int y = dy[i] + b[1];

		if(x<0 || x==row || y<0 || y==col || bo[x][y] == 0)
			continue;
		++cnt;
		bo[b[0]][b[1]] = 0; 
		aDfs(a, aMove, {x,y}, bMove+1);
		bo[b[0]][b[1]] = 1; 
	}

}

int solution(vector<vector<int>> board, vector<int> a, vector<int> b)
{
	bo = move(board);
	row = bo.size();
	col = bo[0].size();
	ans = 0;
	aMinMove = INT32_MAX;
	bMinMove = INT32_MAX;

	aDfs(a,0,b,0);
	return ans;
}

int main(void)
{
	vector<vector<int>> v = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
	vector<int> a = {1,0};
	vector<int> b = {1,2};
	//vector<vector<int>> v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
	//vector<int> a = {1,0};
	//vector<int> b = {1,2};
	//vector<vector<int>> v = {{1,1,1,1,1}};
	//vector<int> a = {0,0};
	//vector<int> b = {0,4};
	//vector<vector<int>> v = {{1}};
	//vector<int> a = {0,0};
	//vector<int> b = {0,0};

	int ans = solution(v,a,b);
	cout << "ans = " << ans << endl;
	return	0;
}
