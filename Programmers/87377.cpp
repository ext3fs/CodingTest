//programmers 교점에 별 만들기(87377)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//답의 범위를 예측하면 쉽게 구현할수 있다.. 

vector<string> solution(vector<vector<int>> line)
{
	set<pair<int64_t,int64_t>> pos;
	int64_t minX = INT64_MAX, maxX = INT64_MIN;
	int64_t minY = INT64_MAX, maxY = INT64_MIN;

	for(size_t i=0; i<line.size(); ++i)
	{
		for(size_t j=i+1; j<line.size(); ++j)
		{
			int64_t d = (int64_t)line[i][0]*line[j][1] - (int64_t)line[i][1]*line[j][0];
			int64_t x = (int64_t)line[i][1]*line[j][2] - (int64_t)line[i][2]*line[j][1];
			int64_t y = (int64_t)line[i][2]*line[j][0] - (int64_t)line[i][0]*line[j][2];
			
			if(d == 0 || x%d || y%d)
				continue;

			x /= d; y /= d;
			minX = min(minX, x); maxX = max(maxX, x);
			minY = min(minY, y); maxY = max(maxY, y);
			pos.insert({x,y});
		}
	}

	vector<string> ans(maxY-minY+1, string(maxX-minX+1,'.'));
	for(auto& e : pos)
		ans[maxY-e.second][e.first-minX] = '*'; 
	return ans;
}

int main(void)
{
	//vector<vector<int>> v = {{1, -1, 0}, {2, -1, 0}, {4, -1, 0}};
	//vector<vector<int>> v = {{0, 1, -1}, {1, 0, -1}, {1, 0, 1}};
	vector<vector<int>> v = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
	vector<string> ans = solution(v);
	
	for(string& s : ans)
		cout << s << endl;
	return	0;
}
