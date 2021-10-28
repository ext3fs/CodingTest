//programmers 야근지수(12927)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works)
{
	priority_queue<int> q(works.begin(), works.end());
	
	while(!q.empty())
	{
		int work = q.top();
		q.pop();
		
		--n;
		--work;
		
		if(work)
			q.push(work);

		if(n == 0)
			break;
	}

	long long ans = 0;
	
	while(!q.empty()){
		ans += q.top() * q.top();
		q.pop();		
	}

	return ans;
}

int main(void)
{
	vector<int> v = {4, 3, 3};
	long long ans = solution(4, v);
	cout << "ans = " << ans << endl;
	return	0;
}
