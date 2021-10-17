//programmers 12945
#include <vector>
#include <iostream>
using namespace std;

/*
   %연산은 분배법칙이 성립하지 않는다.
   (12 + 13)%5 = 0 VS 12%5 + 13%5 = 5
   마지막에 ret%5 해줘야함? 
   */
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

