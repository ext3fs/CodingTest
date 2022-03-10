//programmers 셔틀버스(17678)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> ti)
{
	vector<int> man(ti.size());
	for(int i=0; i<ti.size(); ++i)
		man[i] = stoi(ti[i].substr(0,2))*60 + stoi(ti[i].substr(3,2));
	sort(man.begin(),man.end());

	vector<int> bus(n);	
			

	return "";
}

int main(void)
{
	vector<string> v = {"09:10", "09:09", "08:00"};

	cout << solution(2,10,2,v) << endl;
	return	0;
}

