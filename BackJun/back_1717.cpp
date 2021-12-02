//backjun - 집합의표현(1717) 
#include <iostream>
#include <vector>
using namespace std;

vector<int> group;

int findGroup(int x)
{
	if(x == group[x])
		return x;
	return group[x] = findGroup(group[x]);
}

void unionGroup(int a, int b)
{
	a = findGroup(a);
	b = findGroup(b);

	if(a < b)
		group[b] = a;
	else if(a > b)
		group[a] = b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	group.resize(n+1);
	for(int i=0; i<=n; ++i)
		group[i] = i;	
	
	string yes = "YES\n", no = "NO\n";
	int cmd, a, b;

	for(int i=0; i<m; ++i)
	{
		cin >> cmd >> a >> b;
		
		if(cmd == 0){
			unionGroup(a,b);
			continue;
		}

		if(findGroup(a) == findGroup(b))
			cout << yes;
		else
			cout << no;	
	}

	return 0;
}
