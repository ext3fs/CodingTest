//backjun 11054(가장 긴 바이토닉 수열)
#include <iostream>
using namespace std;

int main(void)
{
	int n, ans=0;
	scanf("%d", &n);
	
	int val[n], inc[n], dec[n];

	for(int i=0; i<n; ++i)
	{
		scanf("%d", val+i);
		inc[i] = 1;
		for(int j=0; j<i; ++j)
			if(val[i] > val[j])
				inc[i] = max(inc[i], inc[j]+1);
	}

	for(int i=n-1; i>=0; --i)
	{
		dec[i] = 1;
		for(int j=n-1; j>i; --j)
			if(val[i] > val[j])
				dec[i] = max(dec[i], dec[j]+1);
	}
	
	for(int i=0; i<n; ++i)
		ans = max(ans, inc[i]+dec[i]-1);
	printf("%d\n", ans);
	return 0;
}
