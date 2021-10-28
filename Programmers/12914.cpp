//programmers 멀리뛰기(12914)
#include <iostream>
#include <vector>
using namespace std;

//dp -> 순서 고려 

int solution(int n)
{
	vector<int> dp(n+1);
	dp[0] = 1;
	
	for(int i=1; i<dp.size(); ++i)
	{
		for(int dist=1; dist<3; ++dist)
		{
			int idx = i - dist;
			
			if(idx < 0)
				continue;
			
			dp[i] += dp[idx];
		}
	}

	return dp[n];
}

int main(void)
{
	int ret = solution(4);
	cout << "ans = " << ret << endl;
	return	0;
}
