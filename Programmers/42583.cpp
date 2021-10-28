//programmers 42583
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int length, int max_wei, vector<int> truck_wei)
{
	int sec=1, curr_wei=truck_wei[0];
	queue<pair<int,int>> bridge;
	queue<int> truck;

	bridge.push(make_pair(truck_wei[0],sec));

	for(size_t i=1; i<truck_wei.size(); ++i)
		truck.push(truck_wei[i]);

	while(1)
	{
		if(truck.empty())
			return sec + length;

		++sec;
		
		if(sec - bridge.front().second == length)
		{
			curr_wei -= bridge.front().first;
			bridge.pop();
		}

		if(bridge.size() < length && curr_wei + truck.front() <= max_wei)
		{
			curr_wei += truck.front();
			bridge.push(make_pair(truck.front(),sec));
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

