//programmers 스타수열(70130)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

/*
   ex) 1 2 3 5 2 4 2
   가장 빈도수가 많은 2부터(빈도수가 3이므로 스타수열 사이즈 6이상 될수없음)
   1 2, 5 2, 4 2 가 스타수열 -> 2의 앞뒤 인덱스가 사용가능한지 판단하면 됨 

   ex) 1 1 1 1 1 2 3 2
   가장 빈도수가 많은 1이지만 스타수열 사이즈는 2
   2는 4임 -> 가장 빈도수가 높다고 스타수열 사이즈가 높은건 아님   
*/

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
	return a.second > b.second;
}

int solution(vector<int> a)
{
	if(a.size() < 2)
		return 0;

	unordered_map<int,int> mp;
	for(auto& val : a)
		++mp[val];

	vector<pair<int,int>> v(mp.begin(),mp.end());
	sort(v.begin(),v.end(),cmp);	

	priority_queue<int> q;
	q.push(0);
	for(auto& p : v)
	{
		if(p.second <= q.top())
			break;

		int succ = 0;
		vector<bool> isUse(a.size());
		
		if(a[0] == p.first)
		{
			isUse[0] = true;
			
			if(a[1] != p.first){
				isUse[1] = true;
				++succ;
			}	
		}

		for(int i=1; i<a.size()-1; ++i)
		{
			if(a[i] != p.first)
				continue;
			
			isUse[i] = true;
       			
			if(isUse[i-1])
			{
				if(a[i+1] == p.first)
					continue;
				else
					isUse[i+1] = true;
			}
			++succ;
		}
		
		if(a[a.size()-1] == p.first && !isUse[a.size()-2])
			++succ;

		q.push(succ);
	}	
	return q.top()*2;
}

int main(void)
{
	//vector<int> v = {0,3,3,0,7,2,0,2,2,0};
	vector<int> v = {5,2,3,3,5,3};
	int ans = solution(v);
	cout << "ans = " << ans << endl;
	return	0;
}
