//programmers 프렌즈4블록(17679)
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

set<pair<int,int>> getDelPos(int row, int col, vector<string>& v)
{
	set<pair<int,int>> pos;

	for(int i=0; i<row-1; ++i)
	{
		for(int j=0; j<col-1; ++j)
		{
			char ch = v[i][j];

			if(ch == ' ')
				continue;
			
			if((ch == v[i][j+1]) && (ch == v[i+1][j]) && (ch == v[i+1][j+1])){
				pos.insert({i,j});
				pos.insert({i,j+1});
				pos.insert({i+1,j});
				pos.insert({i+1,j+1});
			}	
		}	
	}
	return pos;
}

int solution(int row, int col, vector<string> mat)
{
	int ans = 0;

	while(1)
	{
		set<pair<int,int>> pos = getDelPos(row, col, mat);
	
		if(pos.size() == 0)
			break;

		//delete block		
		ans += pos.size();
		for(const auto& p : pos)
			mat[p.first][p.second] = ' ';

		//move block
		for(int j=0; j<col; ++j)
		{
			queue<char> q;
			for(int i=row-1; i>=0; --i)
				if(mat[i][j] != ' ')
					q.push(mat[i][j]);
			
			for(int i=row-1; i>=0; --i)
			{
				if(!q.empty()){
					mat[i][j] = q.front();
					q.pop();
					continue;
				}

				mat[i][j] = ' ';
			}
		}
	}

	return ans;
}

int main(void)
{
	//vector<string> v = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
	vector<string> v = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
	int ans = solution(v.size(), v[0].size(), v);
	cout << "ans = " << ans << endl;
	return	0;
}
