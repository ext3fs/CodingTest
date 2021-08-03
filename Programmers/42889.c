//programmers 42889
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool cmp(pair<int,double>& a, pair<int,double>& b)
{
	if(a.second == b.second)
		return a.first < b.first;
	else
		return	a.second > b.second;
}	

vector<int> solution(int n, vector<int> stages)
{
	sort(stages.begin(), stages.end());

	vector<pair<int,double>> ar(n+2);
	vector<int> answer;
	int stage = 1, cnt = 0;
	//auto* ar = new pair<int, double>[n+2];

	for(int i=0; i<n+2; ++i)
		ar[i].first = i;

	for(int i=0; i<stages.size(); ++i)
	{
		if(stage != stages[i])
		{
			ar[stage].second = static_cast<double>(cnt)/(stages.size() -i + cnt);
			stage = stages[i];
			cnt = 0;	
		}
		++cnt;	
	}
	ar[stage].second = 1; 	

	//sort(ar+1, ar+n+1, cmp);
	sort(ar.begin()+1, ar.end()-1, cmp);

	for(int i=1; i<n+1; ++i)
		answer.push_back(ar[i].first);

	return answer;
}

int	main(void)
{
	vector<int>	numbers = {2,1,2,6,2,4,3,3};
	//vector<int>	numbers = {4,4,4,4,4};

	vector<int> ans = solution(5, numbers);
	//vector<int> ans = solution(4, numbers);
	for(int val : ans)
		cout << val << endl;	
	return	0;
}

