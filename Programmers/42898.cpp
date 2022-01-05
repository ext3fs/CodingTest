//programmers 42898
#include <iostream>
#include <vector>
using namespace std;

/*
오른쪽과 아래쪽으로만 이동한다는 것때문에 dp가 가능 
   
1 1 1 
1 2 3 
1 3 6
*/

int solution(int m, int n, vector<vector<int>> puddles)
{
	vector<vector<int>> mat(n+1,vector<int>(m+1));

	for(size_t i=0; i<puddles.size(); ++i)
		mat[puddles[i][1]][puddles[i][0]] = -1;
	
	//1행 1열도 못가는 경우 & 웅덩이 고려해야함..
	mat[0][1] = 1;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(mat[i][j] < 0)
				mat[i][j] = 0;
			else
				mat[i][j] = (mat[i-1][j] + mat[i][j-1])%1000000007;			
		}
	}

	return mat[n][m];
}

int main(void)
{
	vector<vector<int>> v = {{2,2}};

	int ans = solution(4, 3, v);
	cout << "ans = " << ans << endl;
	return	0;
}

