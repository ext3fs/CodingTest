//backjun 23758(중앙값제거)
#include <iostream>
#include <queue>
using namespace std;

//fail

priority_queue<int> minQ;
priority_queue<int, vector<int>, greater<int>> maxQ;

void putQ(int val)
{
	if(minQ.empty()){
		minQ.push(val);
		return;
	}	

	if(val > minQ.top())
		maxQ.push(val);
	else	
		minQ.push(val);

	if(maxQ.size() > minQ.size())
		minQ.push(maxQ.top()), maxQ.pop();
	else if(minQ.size() - maxQ.size() > 1)
		maxQ.push(minQ.top()), minQ.pop();
}

int getQ(void)
{
	int ret = minQ.top();
	minQ.pop();

	if(maxQ.size() > minQ.size())
		minQ.push(maxQ.top()), maxQ.pop();
	
	return ret;	
}

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n, val, ans = 0;
	cin >> n;

	for(int i=0; i<n; ++i)
		cin >> val, putQ(val);
	
	while(1)
	{
		val = getQ()/2;
		++ans;

		if(val == 0){
			cout << ans << '\n';
			return 0;
		}

		putQ(val);	
	}	
}
