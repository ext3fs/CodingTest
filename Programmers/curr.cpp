//programmers 소수찾기(43839)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> isPrime;
void eratos(int n)
{
	isPrime.resize(n+1,true);
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2; i*i<=n; ++i)
		if(isPrime[i])
			for(int j=i+i; j<=n; j+=i)
				isPrime[j] = false;
}

int ans;
string ts;
vector<bool> isUse;
void permutation(string& num)
{
	if(ts.size())
	{
		int val = stoi(ts);

		if(isPrime[val]){
			++ans;
			isPrime[val] = false;
		}		
	}

	if(ts.size() == num.size())
		return;

	for(size_t i=0; i<num.size(); ++i)
	{
		if(isUse[i])
			continue;

		ts.push_back(num[i]);
		isUse[i] = true;
		permutation(num);
		ts.pop_back();
		isUse[i] = false;
	}
}

int solution(string num)
{
	sort(num.begin(), num.end(), greater<char>());
	eratos(stoi(num));

	ans = 0;	
	ts.reserve(num.size()+1);
	isUse.resize(num.size());
	permutation(num);
	return ans;
}

int main(void)
{
	string s = "17";
	//string s = "011";
	int ans = solution(s);
	cout << "ans = " << ans << endl;
	return	0;
}
