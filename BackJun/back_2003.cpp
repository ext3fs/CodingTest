//backjun 수들의합2(2003) 
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i]; 

	int start = 0, end = 0;
	int sum = 0, ans = 0;
		
	while(1)
	{
		if(end == n && sum < m)
			break;

		if(sum < m)
			sum += v[end++];		
		else if(sum > m)
			sum -= v[start++];
		else{
			++ans;
			sum -= v[start++];
		}
	}

	cout << ans << '\n';
	return 0;	
}
