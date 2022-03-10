//backjun 카드게임(11062)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> cache;

int dfs(vector<int>& v, int begin, int end, bool isA)
{
	if(begin > end)
		return 0;
	
	int& ret = cache[begin][end];
	//pruning
	if(ret > 0)
		return ret;	

	if(isA){	
		int a = v[begin] + dfs(v, begin+1, end, false);
		int b = v[end] + dfs(v, begin, end-1, false);
		ret = max(a,b);
	}	
	else{
		int a = dfs(v, begin+1, end, true);
		int b = dfs(v, begin, end-1, true);
		ret = min(a,b);
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		
		vector<int> v(n);
		for(int i=0; i<n; ++i)
			cin >> v[i];

		cache.assign(n,vector<int>(n,-1));
		cout << dfs(v,0,n-1,true) << '\n';
	}
	return 0;	
}
