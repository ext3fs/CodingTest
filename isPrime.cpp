#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
	if(n<2)
		return false;

	for(int i=2; i*i<=n; ++i)
	{
		if(n%i == 0)
			return	false;
	}
	
	return	true;	
}

int main(void)
{
	cout << solution(9) << endl;	
	return	0;
}

