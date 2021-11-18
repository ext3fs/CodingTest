//programmers 자물쇠와 열쇠(60059)
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

string solution(string sen)
{
	unordered_map<char,int> mp;

	if(islower(sen[0]))
		++mp[sen[0]];

	for(int i=1; i<sen.size(); ++i)
	{
		if(!isalpha(sen[i]))
			return "invalid";
		
		if(islower(sen[i]))
		{
			if(islower(sen[i-1]))
				return "invalid";

			++mp[sen[i]];
		}
	}	
	
	for(auto& p : mp)
	{
		if(p.second != 2)
			continue;
			
		for(char& ch : sen)
			if(p.first == ch)
				ch = ' ';
	}

	cout << "sen = " << sen << endl;

	vector<string> v;
	stringstream ss(sen);
	string token;

	while(ss >> token)
	{
		cout << token << endl;

		if(islower(token.front()) || islower(token.back()))
			return "invalid";

		unordered_map<char,int> mp;
		for(char ch : token)
			if(islower(ch))
				++mp[ch];

		if(mp.size() == 0){
			v.push_back(str);
			continue;	
		}
		
		string s = "";
		s.push_back(sen[0]);
		for(int i=1; i<str.size(); ++i)
		{
			if(islower(sen[i]))
				continue;
		}
	}



/*
	cout << sen << endl;

	string ans = "";
	ans.push_back(sen[0]);

	for(int i=0; i<sen.size(); ++i)
	{
		if(islower(sen[i]))
			continue;

		if(isupper(sen[i]) && isupper(sen[i-1]))
			ans.push_back(' ');
			
		ans.push_back(sen[i]);	
	}	

*/	
	return "";
}

int main(void)
{
	//string s = "AxAxAxAoBoBoB";
	string s = " SpIpGpOpNpGJqOqA";
	//string s = "HaEaLaLaObWORLDb";
	string ans = solution(s);
	cout << "ans = " << ans << endl;
	return	0;
}
