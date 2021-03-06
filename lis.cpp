//backjun 11053 - lis(longest increase subsequence)
#include <iostream>
using namespace std;

int main(void)
{
	int n, ans=0;
	scanf("%d", &n);
	
	int val[n], dp[n];
	for(int i=0; i<n; ++i)
	{
		scanf("%d", val+i);
		dp[i] = 1;
		
		//현재수 i를 기준으로 앞쪽에 자기보다 작은수가 있다면
	        //그것이 가지고 있는 (dp값+1)과 자신이 가지고 있는 dp값중 큰것 선택	
		for(int j=0; j<i; ++j)
			if(val[i] > val[j])
				dp[i] = max(dp[i], dp[j]+1);
		
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}
