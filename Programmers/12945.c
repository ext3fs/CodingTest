//programmers 12945
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
	vector<int> dp(n+1);
	
	dp[1] = 1;
	for(int i=2; i<=n; ++i)
		dp[i] = (dp[i-1] + dp[i-2])%1234567;		

	return dp[n];
}

int	main(void)
{
	cout << solution(3) << endl;
	return	0;
}

