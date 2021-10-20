#include <vector>
#include <iostream>

using namespace std;

vector<int> ar = {1,2,3,4};
vector<int> tv;
vector<bool> use(ar.size());

void permutation(int n, int r)
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
		if(use[i])
			continue;
	
		tv.push_back(ar[i]);
		use[i] = true;
		permutation(n, r);
		tv.pop_back();
		use[i] = false;
	}
}

int main(void)
{
	tv.reserve(ar.size());
	permutation(ar.size(), 3);	
	return 0;
}

