//backjun - 여행가자(1976) 
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> group;

int findGroup(int x){
	if(group[x] == x)
		return x;
	return group[x] = findGroup(group[x]);	
}

void unionGroup(int a, int b)
{
	a = findGroup(a);
	b = findGroup(b);

	if(a < b)
		group[b] = a;
	else
		group[a] = b;
}

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	group.resize(n);
	for(int i=0; i<n; ++i)
		group[i] = i;	
	
	int isConnect;	
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			cin >> isConnect;
			if(isConnect)
				unionGroup(i,j);
		}
	}

	int x;
	unordered_set<int> st;
	for(int i=0; i<m; ++i){
		cin >> x;
		st.insert(findGroup(x-1));	
	}

	if(st.size() == 1)
		cout << "YES\n";
	else	
		cout << "NO\n";
	return 0;
}
