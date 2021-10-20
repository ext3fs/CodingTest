#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	//오름차순으로 정렬되어있어야함
	vector<int> v = {1,2,3,4};
	int r = 2;

	do{
		for(int i=0; i<r; ++i)
			cout << v[i] << ' ';
		cout << '\n';

		//필요없는 뒷부분을 reverse 해서 해당 prefix의 마지막 순열로 만들어준다 
		reverse(v.begin()+r, v.end());

	}while(next_permutation(v.begin(),v.end()));

	return 0;
}

