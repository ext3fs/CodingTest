#include <vector>
#include <iostream>
using namespace std;

vector<int> tv;

void dup_permutation(vector<int>& ar, size_t r)
{
	if(tv.size() == r)
	{
		for(auto& e : tv)
			cout << e << ' ';
		cout << endl;
		return;
	}

	for(size_t i=0; i<ar.size(); ++i)
	{
		tv.push_back(ar[i]);
		dup_permutation(ar, r);
		tv.pop_back();
	}
}

int main(void)
{
	vector<int> ar = {1,2,3};

	tv.reserve(ar.size());		
	dup_permutation(ar,3);
	return	0;
}
