//backjun 2565(전깃줄)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);

	int n, ans=0;
	scanf("%d", &n);
	
	vector<pair<int,int>> v;
	v.reserve(n);
	for(int i=0; i<n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());

	//lis
	vector<int> dp(n,1);
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<i; ++j)
			if(v[i].second > v[j].second)
				dp[i] = max(dp[i], dp[j]+1);

		ans = max(ans, dp[i]);		
	}

	printf("%d\n", n-ans);
	return 0;
}
