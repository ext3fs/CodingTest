//combination by STL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  1. ar에 중복된 원소가 있어도 된다.. 
  2. 하지만 prev_permuation()은 중복된 결과는 출력하지 않는다.
  3. {true,ture,true,false}을 prev_permutation()하면 모든 조합을 구할수 있다..   
*/

int main(void)
{
	vector<int> ar = {1,2,3,4};
	vector<bool> tv(ar.size(), false);
	int r = 3;
		
	for(int i=0; i<r; ++i)
		tv[i] = true;

	do{
		for(int i=0; i<tv.size(); ++i)
			if(tv[i])
				cout << ar[i] << ' ';
		cout << endl;

	}while(prev_permutation(tv.begin(),tv.end()));

	return 0;
}

