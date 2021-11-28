//backjun 1912(연속합)
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i];

	vector<int> dp(n);
	dp[0] = v[0];
	for(int i=1; i<n; ++i)
		dp[i] = max(v[i], v[i] + dp[i-1]);
	
	int ans = INT32_MIN;
	for(int i=0; i<n; ++i)
		ans = max(ans, dp[i]);
	cout << ans << '\n';	
	return 0;
}
