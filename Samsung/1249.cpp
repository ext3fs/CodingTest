//samsung 보급로(1249)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using tiii = tuple<int,int,int>;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int n, vector<string>& mat)
{
	vector<vector<int>> cost(n,vector<int>(n,INT32_MAX));
	priority_queue<tiii, vector<tiii>, greater<tiii>> q;
	
	cost[0][0] = 0;
	q.push({0,0,0});
	while(!q.empty())
	{
		int w = get<0>(q.top());
		int x = get<1>(q.top());
		int y = get<2>(q.top());
		q.pop();
		
		if(cost[x][y] < w)
			continue;	

		for(int i=0; i<4; ++i)
		{
			int nx = x + dx[i];	
			int ny = y + dy[i];
			
			if(nx<0 || nx==n || ny<0 || ny==n)
				continue;

			if(nx == n-1 && ny == n-1)
				return w;

			int nw = w + mat[nx][ny] - '0';
			if(cost[nx][ny] > nw)	
				cost[nx][ny] = nw, q.push({nw,nx,ny});	
		}		
	}

	return 0;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int t, cnt=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> mat(n);
		for(int i=0; i<n; ++i)
			cin >> mat[i];
		cout << '#' << ++cnt << ' ' << bfs(n,mat) << '\n';
	}
	return 0;
}
