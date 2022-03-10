//samsung 보급로(1249)
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

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, cnt=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		vector<int> val(n);
		for(int i=0; i<n; ++i)
			cin >> val[i];

		vector<int> dp1(n);
		dp1[0] = val[0];
		for(int i=1; i<n; ++i)
			dp1[i] = gcd(dp1[i-1],val[i]);
		
		vector<int> dp2(n);
		dp2[n-1] = val[n-1];
		for(int i=n-2; i>=0; --i)
			dp2[i] = gcd(dp2[i+1],val[i]);

		int maxVal = max(dp1[n-2],dp2[1]);
		for(int i=1; i<n-1; ++i)
			maxVal = max(maxVal, gcd(dp1[i-1],dp2[i+1]));
		cout << '#' << ++cnt << ' ' << maxVal << '\n';
	}
	return 0;
}
