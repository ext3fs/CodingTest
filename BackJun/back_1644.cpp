//backjun 1644(소수의 연속합) 
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	//eratos
	vector<bool> isPrime(n+1, true);
	isPrime[0] = isPrime[1] = false;
	for(int i=0; i*i<=n; ++i)
		if(isPrime[i])
			for(int j=i+i; j<=n; j+=i)
				isPrime[j] = false;

	vector<int> v;
	v.reserve(n);
	for(int i=0; i<=n; ++i)
		if(isPrime[i])
			v.push_back(i);
	
	int start=0, end=0;
	int sum=0, ans=0;
	while(1)
	{
		if(end == v.size() && sum < n)
			break;

		if(sum < n)
			sum += v[end++];			
		else if(sum > n)
			sum -= v[start++];
		else
			++ans, sum -= v[start++];
	}

	cout << ans << '\n';	
	return 0;	
}
