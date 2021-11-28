//backjun 1463(1로 만들기) 
#include <iostream>
using namespace std;

//3으로 나누는 것보다 2로 나누는게 더 작은 경우도 있음..

int main(void)
{
	int n;
	scanf("%d", &n);

	int dp[n+1] = {0,};
	
	for(int i=2; i<=n; ++i)
	{
		if(i%3 == 0)
		{
			int tmp = INT32_MAX;
			if(i%2 == 0)
				tmp = dp[i/2] + 1; 
				
			dp[i] = min(dp[i/3] + 1, min(dp[i-1] + 1, tmp)); 
		}	
		else if(i%2 == 0)
			dp[i] = min(dp[i/2] + 1, dp[i-1] + 1); 
		else	
			dp[i] = dp[i-1] + 1;
	}

	printf("%d\n", dp[n]);
	return 0;	
}
