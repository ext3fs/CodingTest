//programmers 72411
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string tmp;
unordered_map<string,int> mp;

void combination(string& order, int idx, int n)
{
	if(tmp.size() > 1)
		++mp[tmp];

	for(int i=idx; i<n; ++i){
		tmp.push_back(order[i]);
		combination(order, i+1, n);
		tmp.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> ans;
	size_t max_len = course[course.size()-1];

	mp.clear();
	for(string& order : orders){
		sort(order.begin(), order.end());
		combination(order, 0, order.size());
	}

	//for(auto& e : mp)
	//	cout << e.first << " : " << e.second << endl;

	vector<vector<pair<int,string>>> vv(max_len+1);
	for(auto& e : mp)
		if(e.second > 1 && e.first.size() <= max_len)
			vv[e.first.size()].push_back({e.second,e.first});		

	/*	
	for(int i=0; i<vv.size(); ++i)
	{
		cout << i << " : "; 
		for(auto& e : vv[i])
			cout << e.second << " ";
		cout << endl; 
	}
	*/

	for(auto& len : course)
	{
		if(vv[len].size() == 0)
			break;
		
		sort(vv[len].begin(), vv[len].end(), greater<>());

		int max_cnt = vv[len][0].first;
	
		for(auto& e : vv[len])
		{
			if(e.first != max_cnt)
				break;

			ans.push_back(e.second);
		}
	}

	sort(ans.begin(), ans.end());
	return ans;
}
int main(void)
{
	vector<string> orders = {"ABCFG","AC","CDE","ACDE","BCFG","ACDEH"};
	vector<int> course = {2,3,4};
	//vector<string> orders = {"XYZ","XWY","WAX"};
	//vector<int> course = {2,3,4};
	
	//vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
	//vector<int> course = {2,3,5};
	
	vector<string> ans = solution(orders, course);


	for(size_t i=0; i<ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	return	0;
}

