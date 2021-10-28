//programmers 12주차(87946)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   1. dun[idx][0] 기준으로 정렬할수도
   2. dun[idx][1] 기준으로 정렬할수도 없다
   3. 완전탐색해야 한다  
*/

int getCnt(vector<int>& v, int k, vector<vector<int>>& dun)
{
	int cnt = 0;

	for(int idx : v)
	{
		if(k < dun[idx][0])
			return cnt;

		k -= dun[idx][1];
		++cnt;	
	}
	return cnt;
}

int solution(int k, vector<vector<int>> dun)
{
	vector<int> v(dun.size());
	for(int i=0; i<v.size(); ++i)
		v[i] = i;	

	int ans = 0;
	do{
		ans = max(ans, getCnt(v,k,dun));
	}while(next_permutation(v.begin(),v.end()));
	return ans;
}

int main(void)
{
	vector<vector<int>> v = {{80,20},{50,40},{30,10}};
	int ans = solution(80, v);
	cout << "ans = " << ans << endl;
	return	0;
}
