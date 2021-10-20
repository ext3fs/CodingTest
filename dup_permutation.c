#include <vector>
#include <iostream>
using namespace std;

vector<int> ar = {1,2,3};
vector<int> tv;

void dup_permutation(int n, int r)
{
	if(tv.size() == r)
	{
		for(auto& e : tv)
			cout << e << ' ';
		cout << endl;
		return;
	}

	for(int i=0; i<n; ++i)
	{
		tv.push_back(ar[i]);
		dup_permutation(n,r);
		tv.pop_back();
	}
}

int main(void)
{
	tv.reserve(ar.size());		
	dup_permutation(ar.size(),3);
	return	0;
}

