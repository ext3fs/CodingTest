//programmers 12949
#include <iostream>
#include <vector>
using namespace std;

/*
   행렬의 곱셈(2X3 * 3X2 = 2X2)

   a b c  *  g h   =   ag + bi + ck  ah + bj + cl           
   d e f     i j       dg + ei + fk  dh + ej + fl
             k l
*/

vector<vector<int>> solution(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> ans(a.size(),vector<int>(b[0].size()));

	for(int i=0; i<a.size(); ++i)
		for(int j=0; j<b[0].size(); ++j)
			for(int k=0; k<a[0].size(); ++k)
				ans[i][j] += a[i][k] * b[k][j];
	return ans;
}

int main(void)
{
	//vector<vector<int>> a = {{1, 4}, {3, 2}, {4, 1}};
	//vector<vector<int>> b = {{3,3},{3,3}};
	vector<vector<int>> a = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}};
	vector<vector<int>> b = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};
	
	vector<vector<int>> ret = solution(a,b);

	for(auto& v : ret){
		for(auto& e : v)
			cout << e << " ";
		cout << endl;
	}
	return	0;
}
