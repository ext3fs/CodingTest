//permuation by STL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  1. ar에 중복된 원소가 있어도 된다.. 
  2. 하지만 next_permuation()은 중복된 결과는 출력하지 않는다.
*/

int main(void)
{
	//must be sort
	vector<int> v = {1,2,3,4};
	int r = 2;

	do{
		for(int i=0; i<r; ++i)
			cout << v[i] << ' ';
		cout << endl;

		//필요없는 뒷부분을 reverse 해서 해당 prefix의 마지막 순열로 만들어준다 
		reverse(v.begin()+r, v.end());

	}while(next_permutation(v.begin(), v.end()));

	return 0;
}

