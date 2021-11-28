//backjun 1450(냅색문제)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   meet in the middle
*/

vector<int> combinationAll(vector<int>& v, int c)
{
	vector<int> ret;

	for(int val=1; val<1<<v.size(); ++val)
	{
		int64_t sum = 0;
		
		for(int i=0; i<v.size(); ++i)
			if(val & (1<<i))
				sum += v[i];

		if(sum <= c)
			ret.push_back(sum);		
	}

	return ret;
}

int main(void)
{
	int n, c;
	cin >> n >> c;

	vector<int> v1(n/2 + n%2), v2(n/2);
	for(int i=0; i<v1.size(); ++i)
		cin >> v1[i];
	for(int i=v1.size(); i<n; ++i)
		cin >> v2[i - v1.size()];

	vector<int> w1 = combinationAll(v1, c);	
	vector<int> w2 = combinationAll(v2, c);	
	int ans = w1.size() + w2.size();
	
	sort(w2.begin(), w2.end());
	for(const int w : w1)
		ans += upper_bound(w2.begin(),w2.end(),c-w) - w2.begin();
	
	cout << ans + 1 << '\n';	
	return 0;
}

/*
//dp solution   
void main(void)
{
	int n, c, obj, ans=0;
	cin >> n >> c;
	
	vector<int> dp(c+1);
	dp[0] = 1;
	for(int i=0; i<n; ++i)
	{
		cin >> obj;

		for(int j=c; j>=obj; --j)
			dp[j] += dp[j-obj];
	}

	for(int j=0; j<=c; ++j)
		ans += dp[j];
	cout << ans << '\n';
	return 0;
}
*/
