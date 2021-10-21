//bitmask all combination
#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	vector<int> ar = {1,2,3,4,5};

	for(int mask=0; mask<1<<ar.size(); ++mask)
	{
		cout << mask << " :	";
		
		for(int i=0; i<ar.size(); ++i)
			if(mask & (1<<i))
				cout << ar[i];
		
		cout << endl;
	}
	return 0;
}
