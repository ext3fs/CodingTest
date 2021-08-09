//backjun 9251 
#include <iostream>
using namespace std;

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	
	int cnt1 = s1.size();
	int cnt2 = s2.size();
	int dp[cnt1+1][cnt2+1] = {};

	for(int i=1; i<=cnt1; ++i)
	{
		for(int j=1; j<=cnt2; ++j)
		{
			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);	
		}

	}

	cout << dp[cnt1][cnt2] << endl;
	return 0;
}
