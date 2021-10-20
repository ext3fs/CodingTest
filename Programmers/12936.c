//programmers 줄서는 방법(12936)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<long long> fac;
set<int> val_set;

int getVal(int order)
{
	int val = 0;

	for(int i : val_set)
	{
		if(--order < 0){
			val = i;
			break;
		}
	}

	val_set.erase(val);
	return val;		
}

void dfs(vector<int>& ans, int n, long long k)
{
	if(n == 0)
		return;

	int share = k / fac[n-1];
	int rest = k % fac[n-1];

	if(rest == 0)
		--share;
		
	ans.push_back(getVal(share));
	dfs(ans, n-1, k - share * fac[n-1]);
}

vector<int> solution(int n, long long k)
{
	fac.resize(n);
	fac[0] = 1;
	for(int i=1; i<n; ++i)
		fac[i] = i * fac[i-1]; 	
	
	val_set.clear();
	for(int i=0; i<n; ++i)
		val_set.insert(i+1);

	vector<int> ans;
	ans.reserve(n);
	dfs(ans,n,k);
	return ans;
}

int main(void)
{
	vector<int> ans = solution(4,6);

	cout << " ans = " << endl;
	for(auto& e : ans)
		cout << e << ' ';
	cout << endl;
	return	0;
}
