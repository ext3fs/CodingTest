//programmers 12905
#include <iostream>
#include <vector>
using namespace std;
           
/*
	   dp

           0 0 0 0 
1 1 1      0 1 1 1 
1 1 1  ->  0 1 2 2
1 1 1	   0 1 2 3 		    
*/

int solution(vector<vector<int>> board)
{
	int max_len = 0;
	int row = board.size() + 1;
	int col = board[0].size() + 1;

	vector<vector<int>> mat(row, vector<int>(col));
	
	for(int i=1; i<row; ++i)
		for(int j=1; j<col; ++j)
			mat[i][j] = board[i-1][j-1];

	for(int i=1; i<row; ++i)
	{
		for(int j=1; j<col; ++j)
		{
			if(mat[i][j] == 0)
				continue;
			
			mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j],mat[i][j-1])) + 1;
			max_len = max(max_len, mat[i][j]);
		}
	}

	return max_len * max_len;
}

int main(void)
{
	//vector<int> v = {1, 2, 3, 2, 3};
	vector<vector<int>> vv = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	//vector<int> ans = solution(v);

	//for(auto& e : ans)
	//	cout << e << endl;
	cout << solution(vv) << endl;
	return	0;
}

