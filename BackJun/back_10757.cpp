//backjun 큰수 A+B (10757) 
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	string a, b;
	cin >> a >> b;	

	reverse(a.begin(), a.end());	
	reverse(b.begin(), b.end());	
	
	int cnt = max(a.size(), b.size());
	for(int i=a.size(); i<cnt; ++i)	
		a.push_back('0');
	for(int i=b.size(); i<cnt; ++i)	
		b.push_back('0');

	int add = 0;	
	string ans;
	for(int i=0; i<cnt; ++i)
	{
		int res = a[i] + b[i] - '0' - '0';
		
		if(add)
			add = 0, ++res;

		if(res > 9)
			add = 1, res %= 10;
			
		ans.push_back(res + '0');
	}

	if(add)
		ans.push_back('1');

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
