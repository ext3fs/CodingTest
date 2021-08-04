//backjun 1389
#include <iostream>
using namespace std;

int main(void)
{
	int n,m,x,y;
	scanf("%d%d", &n, &m);

	int mat[n+1][n+1];
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = 1e9;
		}
	}

	for(int i=0; i<m; ++i){
		scanf("%d%d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	for(int k=1; k<=m; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

	int sum[n+1] = {0,};
	int mini = 1e9;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j)
			sum[i] += mat[i][j];
		mini = min(mini, sum[i]);	
	}
	
	for(int i=1; i<=n; ++i){
		if(mini == sum[i]){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
