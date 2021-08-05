//backjun 1389
#include <iostream>
using namespace std;
const int INF = 1e9;

int main(void)
{
	int n,m,x,y;
	scanf("%d%d", &n, &m);

	int mat[n+1][n+1];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			mat[i][j] = (i == j) ? 0 : INF;	

	for(int i=0; i<m; ++i){
		scanf("%d%d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	int ret, mini=INF;
	for(int i=1; i<=n; ++i)
	{
		int sum = 0;

		for(int j=1; j<=n; ++j)
			sum += mat[i][j];

		if(sum < mini){
			mini = sum;
			ret = i;
		}	
	}
	printf("%d\n", ret);
	return 0;
}
