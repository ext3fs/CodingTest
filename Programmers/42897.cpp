//programmers 도둑질(42897)
#include <iostream>
#include <vector>
using namespace std;

/*
   money			10  2   3   20
   dp[0] 훔치지 않았을 경우	0   10  10  13         		
   dp[1] 훔쳤을 경우		10  2   13  20   		

   1, 현재 집을 훔치지 않았을 경우 -> max(직전의 두경우)  
   2, 현재 집을 훔쳤을 경우	   -> 직전의 훔치지 않았을 경우 + 현재 집의 돈 
   3, 첫째 집을 훔치면 마지막 집을 훔칠수 없다
   	-> max(첫번째 집 빼고 계산한 결과, 마지막 집 빼고 계산한 결과)
 */

int solution(vector<int> money)
{
	int n = money.size();
	vector<vector<int>> dp(n, vector<int>(2));

	for(int i=1; i<n; ++i){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);		
		dp[i][1] = dp[i-1][0] + money[i];		
	}
	int res1 = max(dp[n-1][0], dp[n-1][1]);

	dp[0][1] = money[0];
	for(int i=1; i<n; ++i){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);		
		dp[i][1] = dp[i-1][0] + money[i];		
	}
	int res2 = max(dp[n-2][0], dp[n-2][1]);

	return max(res1, res2);
}

int main(void)
{
	vector<int> v = {10, 2, 3, 20};
	int ans = solution(v);
	cout << "ans = " << ans << endl;	
	return	0;
}
