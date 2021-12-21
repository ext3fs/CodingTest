//programmers 방금그곡(17683)
#include <iostream>
#include <vector>
using namespace std;

string convt(const string& m)
{
	string ret;
	ret.reserve(m.size());

	for(int i=0; i<m.size(); ++i)
	{
		if(m[i] == '#')
			ret.back() = tolower(ret.back());
		else
			ret.push_back(m[i]);
	}

	return ret;
}


bool isRight(const string& m, const string& music, int play)
{
	string s;
	s.reserve(play);

	int j=0;
	for(int i=0; i<play; ++i)
	{
		s.push_back(music[j]);

		if(++j == music.size())
			j = 0;
	}

	if(s.find(m) == string::npos)
		return false;
	return true;
}


string solution(string m, vector<string> musicinfos)
{
	string ans;
	int maxPlay = 0;

	m = convt(m);
	for(const string& s : musicinfos)
	{
		int start = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
		int end = stoi(s.substr(6,2))*60 + stoi(s.substr(9,2));
		int play = end - start;
		int i;
		string name;
		for(i=12; s[i]!=','; ++i)
			name.push_back(s[i]);
		string music = convt(s.substr(i+1));

		if(isRight(m, music, play))
			if(maxPlay < play)
				maxPlay = play, ans = name; 
	}

	return maxPlay ? ans : "(None)";	
}

int main(void)
{
	vector<string> v = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
	string s = "CC#BCC#BCC#BCC#B";
	string ans = solution(s,v);
	cout << ans << endl;	
	return	0;
}
