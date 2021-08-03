//programmers 17681
#include <vector>
#include <iostream>

using namespace std;

string scale(int n, int val)
{
	string str(n, 0);

	for(int i=n-1; i>=0; --i)
	{
		str[i] = val%2 ? '#':' ';
		val = val/2;		
	}
	return str;
}

vector<string> solution(int n, vector<int> ar1, vector<int> ar2)
{
	vector<string> ans;

	for(int i=0; i<n; ++i)
		ans.push_back(scale(n, ar1[i] | ar2[i]));
	
	return ans;
}

int	main(void)
{
	vector<int>	ar1 = {9,20,28,18,11};
	vector<int>	ar2 = {30,1,21,17,28};

	vector<string> ans = solution(5, ar1, ar2);
	for(auto& val : ans)
		cout << val << endl;	
	return	0;
}

