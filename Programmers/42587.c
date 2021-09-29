//programmers 42587
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int ans=1;
	queue<pair<int,int>> q;
	priority_queue<int> pq;

	for(size_t i=0; i<priorities.size(); ++i){
		q.push(make_pair(i,priorities[i]));
		pq.push(priorities[i]);
	}

	while(1)
	{
		pair<int,int> node = q.front();
		q.pop();

		if(node.second == pq.top())
		{
			if(node.first == location)
				return ans;

			++ans;
			pq.pop();
			continue;		
		}

		q.push(node);
	}
}

int main(void)
{
	//vector<int> pri = {2,1,3,2};
	//int loc = 2;
	vector<int> pri = {1,1,9,1,1,1};
	int loc = 0;
	int ans = solution(pri, loc);
	cout << ans << endl;
	return	0;
}

