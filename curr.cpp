//backjun 1753(최단경로) 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{
	return a < b;
}

int main(void)
{
	string s = "";
	vector<pair<int,int>> v;
	sort(v.begin(),v.end(),cmp);
	cout << "end" << endl;


	if(s == "test")
		cout << "a" << endl;
	else
		cout << "b" << endl;
	return	0;
}

