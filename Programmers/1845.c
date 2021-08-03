//programmers 1845
#include <vector>
#include <iostream>
#include <unordered_set>
//#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
	unordered_set<int> s(nums.begin(), nums.end());

	//for(size_t i=0; i<nums.size(); ++i)
	//	s.insert(nums.at(i));
	
	return	min(nums.size()/2, s.size());
}

int	main(void)
{
	vector<int>	nums = {3,3,3,2,2,4};	

	cout << solution(nums) << endl;	
	return	0;
}

