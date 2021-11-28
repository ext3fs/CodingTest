//bitmask all combination
#include <vector>
#include <iostream>
using namespace std;

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
