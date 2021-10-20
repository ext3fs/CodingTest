#include <vector>
#include <iostream>

using namespace std;

vector<int> ar = {1,2,3,4};
vector<int> tv; 

void combination(int start, int n, int r)
{
	if(tv.size() == r)
	{	
		for(auto& e : tv)
			cout << e << " ";
		cout << endl;
		return;	
	}	
	
	for(int i=start; i<n; ++i)
	{
		tv.push_back(ar[i]);
		combination(i+1, n, r);
		tv.pop_back();
	}
}

int	main(void)
{
	tv.reserve(ar.size()); 
	combination(0, ar.size(), 3);	
	return	0;
}

