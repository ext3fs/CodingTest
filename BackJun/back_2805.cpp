//backjun 나무 자르기(2805) 
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, bottom=0, top=0, ret=0;
	cin >> n >> m;
	vector<int> wood(n);
	
	for(int i=0; i<n; ++i){
		cin >> wood[i];
		top = max(top, wood[i]);	
	}

	while(top >= bottom)
	{
		long long sum = 0;
		int mid = (bottom + top)/2;
			
		for(int i=0; i<n; ++i)
			if(wood[i] > mid)
				sum += wood[i] - mid;

		if(sum < m)
			top = mid - 1;
		else
			ret = mid, bottom = mid + 1;
	}
	
	cout << ret << '\n';
	return 0;	
}
