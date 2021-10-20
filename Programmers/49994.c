//programmers 방문길이(49994)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>
using namespace std;

int solution(string dirs)
{
	unordered_map<char,int> mp = {{'U',0},{'D',1},{'L',2},{'R',3}};
	int dx[] = {0,0,-1,1};	
	int dy[] = {1,-1,0,0};	
	
	set<tuple<int,int,int,int>> st;
	int x = 0, y = 0;
	
	for(char ch : dirs)
	{
		int dir = mp[ch];
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if(nx < -5 || nx > 5 || ny < -5 || ny > 5)
			continue;

		st.insert({x,y,nx,ny});	
		st.insert({nx,ny,x,y});
		x = nx;
		y = ny;	
	}

	return st.size()/2;
}

int main(void)
{
	int ret = solution("ULURRDLLU");
	//int ret = solution("LULLLLLLU");
	cout << "ans = " << ret << endl;
	return	0;
}
