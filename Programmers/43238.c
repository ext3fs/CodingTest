//programmers 43238
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
1. time을 이분검색으로 찾는다
2. 정답은 cnt가 항상 n, 하지만 n을 만족하는 time은 여러개일 수 있다
3. start는 n보다 작은 time, end는 n과 같거나 큰 time(유일한 예외는 n이 1인경우)
4. end - start가 1이면 범위가 극한으로 줄여졌음, 0이면 n이 1인경우
 */

long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());
	long long start = times[0];
	long long end = times[times.size()-1] * (long long)n;

	while(1)
	{
		long long cnt = 0;
		long long mid = (start + end)/2;

		for(int val : times)
			cnt += mid/val;
	
		if(cnt < n)
			start = mid;
		else 
			end = mid;

		if(end - start < 2)
			return end;
	}
	return 0;
}

int main(void)
{
	vector<int> v = {7,10};
	long long ans = solution(6,v);
	//vector<int> v = {1,2};
	//long long ans = solution(1,v);
	//vector<int> v = {1,5,10};
	//long long ans = solution(9,v);
	cout << "ans = " << ans << endl;
	return	0;
}


