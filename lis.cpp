//backjun 11053
#include <iostream>
using namespace std;

int main(void)
{
	int n, maxi=0;
	scanf("%d", &n);
	
	//lis(longest increase subsequence)
	int val[n];
	int seq[n] = {0,};

	for(int i=0; i<n; ++i)
	{
		scanf("%d", val+i);
		
		for(int j=0; j<i; ++j)
			if(val[i] > val[j])
				seq[i] = max(seq[i], seq[j]);
		
		maxi = max(maxi,++seq[i]);
	}

	printf("%d\n", maxi);
	return 0;
}
