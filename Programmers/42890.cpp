//programmers 후보키(42890)
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a.size() < b.size();	
}

bool isSubset(const vector<int>& a, const vector<int>& b)
{
	for(int i : a)
		if(find(b.begin(),b.end(),i) == b.end())
			return false;	
	return true;	
}

int solution(vector<vector<string>> db)
{
	int row = db.size();
	int col = db[0].size();
	
	vector<vector<int>> vv;
	for(int val=1; val<1<<col; ++val)
	{
		vector<int> v;

		for(int i=0; i<col; ++i)
			if(val & (1<<i))
				v.push_back(i);

		vv.push_back(move(v));
	}
	sort(vv.begin(),vv.end(),cmp);
	
	vector<vector<int>> succ;
	for(auto& v : vv)
	{
		unordered_set<string> st;
		
		for(auto& suc : succ)
			if(isSubset(suc,v))
				goto Skip;

		for(int i=0; i<db.size(); ++i){
			string str = "";
			for(int j : v)
				str += db[i][j];
			st.insert(move(str));			
		}

		if(st.size() == row)
			succ.push_back(move(v));
		Skip:;
	}
	return succ.size();
}

int main(void)
{
	vector<vector<string>> v = {{"100","ryan","music","2"},{"200","apeach","math","2"},
				    {"300","tube","computer","3"},{"400","con","computer","4"},
				    {"500","muzi","music","3"},{"600","apeach","music","2"}};
	int ans = solution(v);
	cout << "ans = " << ans << endl;
	return	0;
}
