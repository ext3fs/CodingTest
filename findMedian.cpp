//backjun 1655(가운데를 말해요)
#include <iostream>
#include <queue>
using namespace std;

/*
   중앙값 구하기 - O(nlogn)보다 작다 
   1, 중앙값이란? 수열을 정렬했을때 중앙에 오는 값
   2, n사이즈 수열 중앙값의 인덱스는 (n+1)/2 -1; 
*/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, val;
	priority_queue<int> minQ;
	priority_queue<int, vector<int>, greater<int>> maxQ;

	cin >> n >> val;
	minQ.push(val);
	cout << val << '\n';

	for(int i=1; i<n; ++i)
	{
		cin >> val;
		
		if(val > minQ.top())
			maxQ.push(val);
		else
			minQ.push(val);

		if(maxQ.size() > minQ.size())
			minQ.push(maxQ.top()), maxQ.pop();
		else if(minQ.size() - maxQ.size() > 1)
			maxQ.push(minQ.top()), minQ.pop();

		cout << minQ.top() << '\n';
	}

	return 0;
}
