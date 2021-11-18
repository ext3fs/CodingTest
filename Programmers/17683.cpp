//programmers 방금 그 곡(17683)
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string convt(string_view s)
{
	string ret;

	for(char c : s)
	{
		if(c == '#')
			ret.back() = tolower(ret.back());  
		else
			ret.push_back(c);			
	}
	return ret;	
}

string solution(string m, vector<string> musicinfos)
{
	string ans = "";
	int maxLen = 0;

	m = convt(m);

	cout << "m = " << m << endl;
	for(string& s : musicinfos)
	{
		stringstream ss(s);
		int sH, sM, eH, eM;
		string str, name, mel = "";
		char c;
		ss >> sH >> c >> sM >> c >> eH >> c >> eM >> c >> str;
		
		int idx = str.find(',');
		name = str.substr(0,idx);
		str = convt(str.substr(idx+1));
		
		int len = (eH - sH) * 60 + eM - sM;
		int cnt = len/str.size();
		int rest = len%str.size();

		while(cnt--)
			mel += str;
		mel += str.substr(0,rest);	

		cout << sH << c << sM << c << eH << c << eM
			<< c << name << c << str << c << mel << endl;
		
		if(mel.find(m) != string::npos && len > maxLen){
			maxLen = len;
			ans = name;
		}
	}
	
	return ans.size() ? ans : "(None)";
}

int main(void)
{
	vector<string> v = {"03:00,03:30,FOO,CC#B#", "04:00,04:31,BAR,CC#BCC#BCC#B"};
	string s = "CC#BCC#BCC#BCC#B"; 
	//vector<string> v = {"12:00,12:01,HELLO,A#"};
	//string s = "A#"; 
	string ans = solution(s,v);
	cout << "ans = " << ans << endl;
	return	0;
}
