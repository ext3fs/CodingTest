#include <vector>
#include <iostream>

using namespace std;

int ar[] = {1,2,3,4};
vector<int> v; 

void Combination(int idx, int n, int r)
{
	if(v.size() == (size_t)r)
	{	
		for(int i=0; i<r; ++i)
			cout << v[i] << " ";
		cout << endl;
		return;	
	}	
	
	for(int i=idx; i<n; ++i)
	{
		v.push_back(ar[i]);
		Combination(i+1, n, r);
		v.pop_back();
	}
}

int	main(void)
{
	Combination(0, 4, 2);	
	return	0;
}

