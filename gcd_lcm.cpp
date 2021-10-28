#include <vector>
#include <iostream>
using namespace std;

/*
   1. gcd(a,b) = gcd(b,a%b) -> gcd(a,0) = a;
   2. lcm = a*b/gcd(a,b)
*/

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

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int main(void)
{
	cout << gcd(6,4) << endl;	
	return 0;
}

