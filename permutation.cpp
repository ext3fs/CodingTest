#include <vector>
#include <iostream>
using namespace std;

vector<int> tv;
vector<bool> isUse;

void permutation(vector<int>& ar, size_t r)
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
		if(isUse[i])
			continue;
	
		tv.push_back(ar[i]);
		isUse[i] = true;
		permutation(ar, r);
		tv.pop_back();
		isUse[i] = false;
	}
}

int main(void)
{
	vector<int> ar = {1,2,3,4};

	tv.reserve(ar.size());
	isUse.resize(ar.size());
	permutation(ar, 3);	
	return 0;
}

