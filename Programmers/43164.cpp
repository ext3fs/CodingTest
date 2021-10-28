//programmers 43164
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string,vector<bool>> visit;
vector<string> ans;
vector<string> tmp;
size_t ticket_cnt;

void dfs(unordered_map<string,vector<string>>& mp, string& start)
{
	if(ans.size())
		return;

	if(tmp.size() == ticket_cnt){
		ans.push_back("ICN");
		for(string& s : tmp)
			ans.push_back(s);
		return;
	}
	
	vector<string>& v = mp[start];  
	for(size_t i=0; i<v.size(); ++i)
	{
		if(visit[start][i])
       			continue;

		visit[start][i] = true;
		tmp.push_back(v[i]);
		dfs(mp,v[i]);
		tmp.pop_back();
		visit[start][i] = false;
	}	
}

vector<string> solution(vector<vector<string>> tickets)
{
	unordered_map<string,vector<string>> mp;
	
	ticket_cnt = tickets.size();	
	ans.clear();
	visit.clear();

	for(auto& v : tickets)
		mp[v[0]].push_back(v[1]);

	for(auto& e : mp){
		sort(e.second.begin(), e.second.end());
		visit.insert({e.first,vector<bool>(e.second.size())});
	}

	string s = "ICN";
	dfs(mp,s);	
	return ans;
}

int main(void)
{
	vector<vector<string>> v
		= {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
	vector<string> ans = solution(v);
	for(auto& e : ans)
		cout << e << " ";
	cout << endl;
	return	0;
}


