//bitmask all combination
#include <vector>
#include <iostream>
using namespace std;

//모든조합의 경우의 수는 O(2^N) -> 각 N마다 2가지 경우의 bit   

void combinationAll(vector<int>& v)
{
	for(int val=1; val<1<<v.size(); ++val)
	{
		cout << val << " :	";
		
		for(int i=0; i<v.size(); ++i)
			if(val & (1<<i))
				cout << v[i];
		cout << endl;
	}
}

int main(void)
{
	vector<int> v = {1,2,3,4,5};
	combinationAll(v);
	return 0;
}
