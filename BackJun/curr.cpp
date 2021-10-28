//backjun 9251 
#include <iostream>
using namespace std;

int dfs(int n)
{
	if(n < 2)
		return 0;

	return dfs(n-1) + dfs(n-2);
}

int main(void)
{
	int n = 10;

	cout << dfs(n) << endl;
	return 0;
}
