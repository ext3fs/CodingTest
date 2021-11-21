//backjun 2110(공유기설치) 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;
	vector<int> pos(n);
	for(int i=0; i<n; ++i)
		cin >> pos[i];
	sort(pos.begin(), pos.end());

	int start = 1, end = pos.back() - pos.front();
	int ret = 0;
	while(end >= start)
	{
		int dist = (start + end)/2;
		int cnt = c - 1;
		int prev = pos[0];

		for(int i=1; i<n; ++i)
		{
			if(pos[i] - prev < dist)
				continue;
			
			--cnt;
			prev = pos[i];
		}
		
		if(cnt > 0)
			end = dist - 1;
		else
			ret = dist, start = dist + 1;
 	}

	cout << ret << '\n';
	return 0;	
}
