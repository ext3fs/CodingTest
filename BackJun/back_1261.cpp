#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using tup = tuple<int,int,int>;

int col, row;
vector<string> mat;
vector<vector<int>> dist;

int dijkstra(void)
{
	priority_queue<tup,vector<tup>,greater<tup>> q;

	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};

	dist[0][0] = 0;
	q.push(make_tuple(0,0,0));

	while(!q.empty())
	{
		int cost = get<0>(q.top());			
		int x = get<1>(q.top());			
		int y = get<2>(q.top());
		q.pop();

		if(x==row-1 && y==col-1)
			return cost;

		if(dist[x][y] < cost)
			continue;

		for(int i=0; i<4; ++i)
		{
			int ncost = cost;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx<0||nx==row||ny<0||ny==col)
				continue;
			
			if(mat[nx][ny] == '1')
				ncost += 1;	

			if(dist[nx][ny] > ncost){
				dist[nx][ny] = ncost;
				q.push(make_tuple(ncost,nx,ny));
			}	
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> col >> row;
	for(int i=0; i<row; ++i){
		cin >> s;
		mat.push_back(s);
	}
	dist.resize(row,vector<int>(col,2e9));	

	cout << dijkstra() << endl;
	return 0;
}
