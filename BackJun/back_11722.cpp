//backjun 11722 - lds(longest decrease subsequence)
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
		
		for(int j=0; j<i; ++j)
			if(val[i] < val[j])
				dp[i] = max(dp[i], dp[j]+1);
		
		ans = max(ans, dp[i]);
	}

	printf("%d\n", ans);
	return 0;
}
