//backjun - 친구네트워크(4195) 
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,pair<string,int>> group;

string findGroup(const string& x)
{
	if(x == group[x].first)
		return x;
	return group[x].first = findGroup(group[x].first); 	
}

int unionGroup(string& a, string& b) 
{
	if(group.count(a) == 0)
		group.insert({a,{a,1}});	
	
	if(group.count(b) == 0)
		group.insert({b,{b,1}});

	a = findGroup(a);
	b = findGroup(b);

	if(a == b)
		return group[a].second;

	group[b].first = a;
	return group[a].second += group[b].second;
}

int main(void)
{
	int t;
	cin >> t;

	int n;
	string a, b;
	while(t--)
	{
		cin >> n;
		group.clear();

		while(n--){
			cin >> a >> b;
			cout << unionGroup(a,b) << '\n';	
		}
	}	
	return 0;
}
