//programmers 튜플(64065)
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(string s)
{
	unordered_map<int,int> mp;
	string tmp = "";
	for(char ch : s)
	{
		if(isdigit(ch)){
			tmp.push_back(ch);
			continue;
		}

		if(tmp.size()){
			++mp[stoi(tmp)];
			tmp.clear();
		}
	}

	set<pair<int,int>,greater<>> st;
	for(auto& e : mp)
		st.insert({e.second, e.first});
			
	vector<int> ans;
	for(auto& e : st)
		ans.push_back(e.second);
	return ans;
}

int main(void)
{
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> ret = solution(s);

	cout << "ans = " << endl;
	for(auto& e : ret)
		cout << e << " ";
	cout << endl;
	return	0;
}
