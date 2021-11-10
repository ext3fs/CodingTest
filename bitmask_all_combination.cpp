//bitmask all combination
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	vector<int> ar = {1,2,3,4,5};

	for(int val=1; val<1<<ar.size(); ++val)
	{
		cout << val << " :	";
		
		for(int i=0; i<ar.size(); ++i)
			if(val & (1<<i))
				cout << ar[i];
		cout << endl;
	}

	return 0;
}
