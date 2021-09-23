//programmers 84512
#include <vector>
#include <iostream>
using namespace std;

string str;
string ret;

void overlap_permutation(int depth, int n, int r)
{
	if(depth == r)
	{
		cout << ret << endl;
		return;
	}

	for(int i=0; i<n; ++i)
	{
		ret.push_back(str[i]);
		overlap_permutation(depth+1, n, r);
		ret.pop_back();
	}
}

void solution(string word)
{
	str = word;
	overlap_permutation(0, str.size(), str.size());
}

int main(void)
{
	solution("AB");
	return	0;
}

