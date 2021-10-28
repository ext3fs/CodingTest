//programmers 42862
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int lost_cnt = 0;
	unordered_set<int> s;
	vector<int> v;

	for(int i : reserve)
		s.insert(i);

	for(int i : lost)
	{
		if(s.erase(i))
			continue;
		v.push_back(i);	
	}

	for(int i : v)
	{
		if(s.erase(i-1) || s.erase(i+1))
			continue;
		++lost_cnt;	
	}

	return n - lost_cnt;
}

int	main(void)
{
	vector<int>	lost = {2,4};
	vector<int>	reserve = {1,3,5};
	
	cout << solution(5, lost, reserve) << endl;	
	return	0;
}

