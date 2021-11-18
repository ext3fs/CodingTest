//programmers 보석쇼핑(67258)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems)
{
	unordered_set<string> st;
	for(auto& gem : gems)
		st.insert(gem);

	int start = 0, end = 0;
	int minSize = INT32_MAX;
	unordered_map<string,int> mp;
	vector<int> ans(2);

	while(1)
	{
		if(end == gems.size() && mp.size() != st.size())
			return ans;

		if(mp.size() == st.size())
		{
			if(end - start < minSize){
				ans[0] = start+1;
				ans[1] = end;
				minSize = end - start;
			}

			if(mp[gems[start]] == 1)
				mp.erase(gems[start]);
			else	
				--mp[gems[start]];
			++start;	
		}
		else
		{
			++mp[gems[end]];
			++end;
		}
	}
}

int main(void)
{
	//vector<string> v = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	//vector<string> v = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
	vector<string> v = {"AA"};
	vector<int> ans = solution(v);
	cout << "ans = " << ans[0] << " , " << ans[1] << endl;
	return	0;
}
