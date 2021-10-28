//programmers 12907
#include <iostream>
#include <vector>
using namespace std;

/*
   1. dp[n] -> n원을 만들때 가질수 있는 경우의 수
   2. dp[0] = 1 -> 0원을 만들수 있는 경우의 수는 1이다
   3. 2원으로 만들수 있는 dp[] = {1,0,1,0,1,0,1,0,1,0,1} 
      -> 2원으로 10원을 만들수있는 경우의 수 = 10원을 만들수있는 경우의 수 + 8원을 만들수있는 경우의 수
   4. 3원으로 만들수 있는 dp[] = {1,0,1,1,1,1,2,1,2,2,2}  
      -> 3원으로 10원을 만들수있는 경우의 수 = 10원을 만들수있는 경우의 수 + 7원을 만들수있는 경우의 수
*/

int solution(int n, vector<int> coins)
{
	vector<int> dp(n+1);
	dp[0] = 1;

	for(int coin : coins)
	{
		cout << "coin = " << coin << endl;
		for(int i=coin; i<=n; ++i)
		{
			dp[i] += dp[i-coin];
			cout << " dp[" << i << "] += " << "dp[" << i-coin << "] -> " << dp[i] << endl;
		}			
	}

	return dp[n];
}

int main(void)
{
	vector<int> v = {2,3};
	int ret = solution(6,v);
	cout << "ret = " << ret << endl;
	return	0;
}
