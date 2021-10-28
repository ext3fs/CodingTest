//programmers 하노이의 탑(12946)
#include <iostream>
#include <vector>
using namespace std;

void hanoi(vector<vector<int>>& ans, int cnt, int src, int dst)
{
	if(cnt == 1){
		ans.push_back({src,dst});
		return;
	}

	hanoi(ans, cnt-1, src, 6-src-dst);
	ans.push_back({src,dst});
	hanoi(ans, cnt-1, 6-src-dst, dst);
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> ans;
	
	hanoi(ans,n,1,3);
	return ans;
}

template<typename T>
void print(T obj)
{
	for(auto& e : obj)
		cout << e << ' ';
	cout << endl;	
}

int main(void)
{
	vector<vector<int>> ans = solution(2);

	cout << " ans = " << endl;
	for(auto& e : ans)
		print<vector<int>>(e);
	return	0;
}
