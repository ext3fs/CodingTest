//backjun 1806(부분합) 
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i];

	if(s == 0){
		cout << "1\n";
		return 0;	
	}

	int start = 0, end = 0;
	int sum = v[0], ans = INT32_MAX;
	
	while(1)
	{
		if(end == n && sum < s)
			break;

		if(sum < s)
			sum += v[end++];
		else
			ans = min(ans, end - start), sum -= v[start++];
 	}

	if(ans == INT32_MAX)
		ans = 0;
	cout << ans << '\n';
	return 0;	
}
