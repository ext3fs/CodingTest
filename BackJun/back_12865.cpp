//backjun 12865(평범한 배낭)
#include <iostream>
#include <vector>
using namespace std;

/*
                dp table  
		0  1  2  3  4  5  6  7    <- idx(배낭의 사이즈)  
		0  0  0  0  0  0  0  0
obj(6, 13)	0  0  0  0  0  0  13 13
obj(4, 8)	0  0  0  0  8  8  13 13
obj(3, 6)	0  0  0  6  8  8  13 14
obj(5, 12)	0  0  0  6  8  12 13 14


1, dp[i][j] -> i는 obj[i]을 넣었을때, j는 배낭사이즈, dp[i][j]는 가치의 합
2, obj[1]을 넣었을때 배낭사이즈 6,7의 가치는 13
3, obj[2]를 넣었을때 
	배낭사이즈 4,5의 가치는 8
	배낭사이즈 6,7의 가치는 obj[2]를 넣지않고 위의것을 계승하는것이 더 크다
4, obj[3]를 넣었을때 
	배낭사이즈 3의 가치는 6
	배낭사이즈 4,5,6의 가치는 obj[3]를 넣지않고 위의것을 계승하는것이 더 크다
	배낭사이즈 7은 위의 배낭사이즈 4의 8과 현재 obj[3]의 가치 6을 더하는 것이 더 크다 
5 점화식
	dp[i][j] = max(dp[i-1][j], dp[i-1][j - obj[i]의 무게] + obj[i]의 가치) 
*/

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<pair<int,int>> obj(n+1);
	for(int i=1; i<=n; ++i)
		cin >> obj[i].first >> obj[i].second;

	vector<vector<int>> dp(n+1, vector<int>(k+1));
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=k; ++j)
		{
			int w = j - obj[i].first;
			int v = obj[i].second;

			if(w < 0)
				w = 0, v = 0;

			dp[i][j] = max(dp[i-1][j], dp[i-1][w] + v);
		}
	}
	
	cout << dp[n][k] << '\n';	
	return 0;
}
