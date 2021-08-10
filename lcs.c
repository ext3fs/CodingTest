//backjun 9251 
#include <iostream>
#include <sstream>
using namespace std;
/*
    NUL a c b 				
NUL 0   0 0 0  	cmp(NUL, a) = 0
a   0		cmp(NUL, ac) = 0	
b   0		cmp(NUl, acb) = 0
c   0		cmp(XXX, NUl)도 마찬가지

    NUL a c b 				
NUL 0   0 0 0  	cmp(a, a) = 1
a   0	1 1 1	cmp(a, ac) = 1	
b   0		cmp(a, acb) = 1
c   0

    NUL a c b 				
NUL 0   0 0 0  	cmp(ab, a) = 1
a   0	1 1 1	cmp(ab, ac) = 1	
b   0	1 1 2	cmp(ab, acb) = 2
c   0

    NUL a c b 				
NUL 0   0 0 0  	cmp(abc, a) = 1
a   0	1 1 1	cmp(abc, ac) = 2  -> cmp(ab, a) 에서 같이 c가 붙었으므로 +1
b   0	1 1 2	cmp(abc, acb) = 2  -> cmp(abc, ac) 와 cmp(ab, acb) 중 큰값  
c   0   1 2 2                          
*/

int main(void)
{
	stringstream ss;
	ss << "abc acb";

	string s1, s2;
	//cin >> s1 >> s2;
	ss >> s1 >> s2;	

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
