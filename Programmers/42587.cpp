//programmers 42587
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> pri, int loc)
{
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0; i<pri.size(); ++i)
        q.push(i), pq.push(pri[i]);
    
    int cnt=0;
    while(1)
    {
        int idx = q.front();
	q.pop();
        
	if(pri[idx] == pq.top())
	{
            pq.pop();
            ++cnt;

            if(idx == loc)
		return cnt;          
        }
	else
      	  q.push(idx);
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

