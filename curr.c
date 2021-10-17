#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	while(1)
	{
		int rest = a%b;

		a = b;
		b = rest;

		if(b == 0)
			return a;
	}
}

int	main(void)
{
	cout << gcd(4,6) << endl;	
	return	0;
}

