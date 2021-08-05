#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int rest;

	while((rest = a%b))
	{
		a = b;
		b = rest;		
	}

	return b;
}

int	main(void)
{
	cout << gcd(6,4) << endl;	
	return	0;
}

