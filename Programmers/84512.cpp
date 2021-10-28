//programmers 84512
#include <iostream>
using namespace std;

int solution(string word)
{
	string s = "AEIOU";
	int ans = word.size();
	int wei[] = {781, 156, 31, 6, 1};

	cout << s << endl;
	cout << word << endl;
	for(size_t i=0; i<word.size(); ++i)
	{
		cout << ans << " + " << s.rfind(word[i]) << " * " << wei[i] <<endl;
		ans += s.rfind(word[i]) * wei[i];	
	}

	return ans;
}

int main(void)
{
	cout << solution("AAAAA") << endl;
	cout << solution("AAAAE") << endl;
	cout << solution("AAAE") << endl;
	return	0;
}

