//programmers n^2 배열자르기(87390)
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right)
{
	//ans의 갯수를 미리 알수있다
	int cnt = right - left + 1;
	vector<int> ans(cnt);

	//left의 matrix row와 col을 계산할수 있다
	int row = left/n;
	int col = left%n;

	for(int i=0; i<cnt; ++i)
	{
		//matrix의 값은 max(i,j) + 1 
		ans[i] = max(row,col) + 1;

		if(++col == n){
			++row;
			col = 0;
		}
	}
	return ans;
}

int main(void)
{
	vector<int> ans = solution(3,2,5);
	for(int i : ans)
		cout << i << ' ';
	cout << endl;
	return	0;
}
