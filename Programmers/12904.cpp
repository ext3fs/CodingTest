//programmers 가장긴펠린드롬(12904)
#include <iostream>
using namespace std;

int getSymmetryCnt(const string& s, int left, int right)
{
	int cnt = 0;

	while(1)
	{
		if(left < 0 || right == s.size() || s[left] != s[right])
			break;

		++cnt;
		--left, ++right;
	}

	return cnt;
}

int solution(string s)
{
	int ans = 0, cnt;

	for(int i=1; i<s.size(); ++i)
	{
		cnt = getSymmetryCnt(s, i-1, i+1);
		ans = max(ans, cnt*2+1);

		//짝수인 경우 -> ex) baab 	
		if(s[i-1] == s[i]){
			cnt = getSymmetryCnt(s, i-2, i+1);
			ans = max(ans, cnt*2+2);
		}
	}

	return ans;	
}

int main(void)
{
	string s = "cdeebbeebbe";
	int ans = solution(s);
	cout << ans << endl;	
	return	0;
}
