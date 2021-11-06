//programmers 쿼드압축후 개수세기(68936)
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


unordered_map<char,char> mp = {{'(',')'},{')','('}};

void split(string& p, string& u, string& v)
{
	int i=0, cnt0=0, cnt1=0;
	
	for(; i<p.size(); ++i)
	{
		if(p[i] == '(')
			++cnt0;
		else
			++cnt1;

		if(cnt0 == cnt1)
			break;
	}
		
	u = p.substr(0,i+1);
	v = p.substr(i+1);
}

bool isRight(string& s)
{
	stack<char> stk;
	
	for(char c : s)
	{
		if(!stk.empty() && stk.top() == '(' && c == ')')
			stk.pop();
		else
			stk.push(c);
	}

	if(stk.empty())
		return true;
	return false;	
}

string convt(string& s)
{
	string tmp = "";
	
	for(int i=1; i<s.size()-1; ++i)
		tmp.push_back(mp[s[i]]);
	return tmp;
}

string dfs(string& p)
{
	if(p.size() == 0)
		return "";

	string u, v;  
	split(p,u,v);

	if(isRight(u))
		return u + dfs(v);
	else
		return "(" + dfs(v) + ")" + convt(u);
}

string solution(string p)
{
	return dfs(p);
}

int main(void)
{
	string s = "()))((()";
	//string s = "(()())()";
	//string s = ")(";
	string ans = solution(s);
	cout << "ans = " << ans << endl;
	return	0;
}
