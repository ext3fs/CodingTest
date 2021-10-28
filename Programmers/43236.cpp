//programmers 43236
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
   1. mid가 답이려면 mid값보다 작은 간격이 있으면 안된다.
   2. 작은 간격이 있으면 돌을 없애서 간격을 넓여야 한다.
   3. n을 만족하는 최소값들중 최대값이므로 n을 만족하는 답중 제일 큰것.
*/
int solution(int distance, vector<int> rocks, int n)
{
	if(rock.size() == n)
		return distance;

	sort(rocks.begin(), rocks.end());

	int start = 0;
	int end = distance;

	while(1)
	{
		int mid = (start + end)/2;
		int cnt = 0;
		int prev = 0;

		for(int i=0; i<rocks.size(); ++i)
		{
			if(rocks[i] - prev < mid)
				++cnt;
			else
				prev = rocks[i];
		}

		if(distance - prev < mid)
			++cnt;

		if(cnt <= n)
			start = mid;
		else
			end = mid;

		if(end - start < 2)
			return start;
	}
}

int main(void)
{
	vector<int> v = {2, 14, 11, 21, 17};
	int ans = solution(25,v,2);
	//vector<int> v = {1};
	//int ans = solution(1,v,1);
	//vector<int> v = {3,5,11};
	//int ans = solution(20,v,2);

	cout << "ret = " << ans << endl;
	return	0;
}
