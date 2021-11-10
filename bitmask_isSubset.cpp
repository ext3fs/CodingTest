#include <vector>
#include <iostream>
using namespace std;

/*
7 -> 0111
6 -> 0110

6은 7의 부분집합이다
*/

bool isSubSet(int a, int b)
{
	if((a & b) == a)
		return true;
	return false;
}

int main(void)
{
	cout << isSubSet(6,7) << endl;
	return 0;
}
