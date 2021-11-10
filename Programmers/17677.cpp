//programmers 뉴스클러스터링(17677)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isRight(string& str)
{
	for(char& ch : str)
	{
		if(isalpha(ch))
			ch = tolower(ch);
		else
			return false;	
	}
	return true;
}

int solution(string s1, string s2)
{
	multiset<string> mst1, mst2;

	for(int i=1; i<s1.size(); ++i){
		string str = s1.substr(i-1,2);
		if(isRight(str))
			mst1.insert(move(str));
	}

	for(int i=1; i<s2.size(); ++i){
		string str = s2.substr(i-1,2);
		if(isRight(str))
			mst2.insert(move(str));
	}

	int sum = mst1.size() + mst2.size();
	if(sum == 0)
		return 65536;

	int cnt = 0;	
	for(auto& str : mst1)
	{
		auto iter = mst2.find(str);
		
		if(iter == mst2.end())
			continue;
	
		++cnt;
		mst2.erase(iter);
	}
	return (cnt * 65536)/(sum - cnt);
}

int main(void)
{
	string s1 = "shake hands";
	string s2 = "handshake";
	//string s1 = "FRANCE";
	//string s2 = "french";

	int ans = solution(s1,s2);
	cout << "ans = " << ans << endl;
	return	0;
}
