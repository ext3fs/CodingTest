//programmers 숫자의 표현(12924)
#include <iostream>
#include <vector>
using namespace std;

//구간합 & two pointer

int solution(int n)
{
	vector<int> dp(n+1);
	
	for(int i=1; i<=n; ++i)
		dp[i] = i + dp[i-1];
		
	int ans = 0;
	int start = 0, end = 1;

	while(end <= n)
	{
		int sum = dp[end] - dp[start];

		if(sum == n)
			++ans;

		if(sum <= n)
			++end;	
		else
			++start;
	}

	return ans;
}

int main(void)
{
	int ret = solution(3);
	cout << "ans = " << ret << endl;
	return	0;
}
