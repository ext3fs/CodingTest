//programmers 다리를 지나는 트럭 (42583)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
   1. bridge에는 1초에 한대씩 들어갈수 있다..
   2. bridge에서 1초에 한대씩 빠질수 있다.. 
 */

int solution(int len, int max_wei, vector<int> truck_wei)
{
	queue<int> truck;
	for(size_t i=0; i<truck_wei.size(); ++i)
		truck.push(truck_wei[i]);

	queue<pair<int,int>> bridge;
	int sec=1, bridge_wei=0;
	
	bridge.push({truck.front(),sec+len});
	bridge_wei += truck.front();
	truck.pop();

	while(1)
	{
		if(truck.empty())
			return bridge.back().second;

		++sec;
		
		if(bridge.front().second == sec)
		{
			bridge_wei -= bridge.front().first;
			bridge.pop();
		}

		if(bridge.size() < len && bridge_wei + truck.front() <= max_wei)
		{
			bridge.push({truck.front(),sec+len});
			bridge_wei += truck.front();
			truck.pop();
		}
	}	
}

int main(void)
{
	vector<int> truck = {7,4,5,6};
	int ans = solution(2, 10, truck);
	cout << ans << endl;
	return	0;
}

