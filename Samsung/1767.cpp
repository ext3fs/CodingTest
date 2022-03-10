//samsung 1767(프로세서 연결하기)
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n, val;
		cin >> n;
		
		vector<vector<int>> board(n,vector<int>(n));
		vector<pair<int,int>> v;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cin >> val;
				board[i][j] = val;
				if(val==0 || i==0 || j==0 || i==n-1 || j==n-1)
					continue;
				v.push_back({i,j});	
			}
		}

		dfs(board,v,0,0);
	}
	return 0;	
}
