//programmers 84512
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
	A	*A	**A	***A	****A
	E	*E	**E	***E	****E	
	781	156	31	 6       1     의 차이

	A -> AA -> AAA -> AAAA -> AAAAA -> AAAAE -> AAAAI -> AAAAO -> AAAAU
			  AAAE -> AAAEA -> AAAEE -> AAAEI -> AAAEO -> AAAEU	
*/

int solution(string word)
{
	string s = "AEIOU";
	unordered_map<char,int> idx;
	for(int i=0; i<s.size(); ++i)
		idx.insert({s[i],i});

	//int wei[] = {781, 156, 31, 6, 1};
	vector<int> wei(5,1);
	for(int i=3; i>=0; --i)
		wei[i] = wei[i+1]*5 + 1;
					
	int ans = 0;
	for(int i=0; i<word.size(); ++i)
		ans += wei[i] * idx[word[i]] + 1;	

	return ans;
}

int main(void)
{
	//cout << solution("AAAAA") << endl;
	//cout << solution("AAAAE") << endl;
	cout << solution("EIO") << endl;
	return	0;
}

