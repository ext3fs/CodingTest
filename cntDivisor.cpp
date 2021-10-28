#include <iostream>

using namespace std;

int cntDivisor(int n)
{
	int i, cnt=0;

	for(i=1; i*i<n; ++i)
	{
		if(n%i == 0)
			cnt += 2;
	}

	if(i*i == n)
		++cnt;
	
	return	cnt;	
}

int	main(void)
{
	cout << cntDivisor(9) << endl;	
	return	0;
}

