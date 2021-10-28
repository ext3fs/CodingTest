//programmers 12953
#include <iostream>
#include <vector>
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

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int solution(vector<int> ar)
{
	int ans = ar[0];

	for(int i=1; i<ar.size(); ++i)
		ans = lcm(ans, ar[i]);

	return ans;
}

int main(void)
{
	vector<int> v = {2,6,8,14};
	//vector<int> v = {1,2,3};
	int ret = solution(v);
	cout << "ret = " << ret << endl;
	return	0;
}
