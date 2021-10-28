//programmers 최고의 집합(12938)
#include <iostream>
#include <vector>
using namespace std;

/*
   1. 원소들의 표준편차가 가장 작은 집합이 답
   2. n = 4, s = 18 일때
   	18/4 -> {4,4,4,4}
	18%4 = 2를 1씩 나누어줌 -> {4,4,5,5}
*/

vector<int> solution(int n, int s)
{
	int base = s/n;
	int rest = s%n;

	if(base == 0)
		return {-1};
	
	vector<int> ans(n,base);
	
	while(rest--)
		++ans[--n];
	
	return ans;
}

int main(void)
{
	vector<int> ans = solution(1,9);

	for(auto& e : ans)
		cout << e << ' ';
	cout << endl;
	return	0;
}
