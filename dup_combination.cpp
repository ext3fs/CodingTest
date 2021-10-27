#include <vector>
#include <iostream>
using namespace std;

vector<int> tv; 

void dup_combination(vector<int>& ar, size_t r, size_t start)
{
	if(tv.size() == r)
	{	
		for(auto& e : tv)
			cout << e << " ";
		cout << endl;
		return;	
	}	
	
	for(size_t i=start; i<ar.size(); ++i)
	{
		tv.push_back(ar[i]);
		dup_combination(ar, r, i);
		tv.pop_back();
	}
}

int	main(void)
{
	vector<int> ar = {1,2,3,4};

	tv.reserve(ar.size()); 
	dup_combination(ar, 3, 0);	
	return	0;
}

