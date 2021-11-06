//programmers 삼각달팽이(68645)
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n)
{
	vector<vector<int>> vv(n);
	int finalVal = 0;
	
	for(int i=0; i<n; ++i){
		vv[i].resize(i+1);
		finalVal += i+1;
	}

	bool isDown = true;
	int i = -1, j = 0;
	int val = 0;
	int targetLine = n - 1; 
		
	while(val < finalVal)
	{
		if(isDown)
		{
			vv[++i][j] = ++val;

			if(i == targetLine)
			{
				while(++j <= i && vv[i][j] == 0)
					vv[i][j] = ++val;
				
				--j;
				--targetLine;
				isDown = false;
			}

			continue;
		}

		if(vv[i-1][j-1])
			isDown = true;
		else	
			vv[--i][--j] = ++val;
	}

	vector<int> ans;
	ans.reserve(finalVal);
	for(auto& v : vv)
		for(int i : v)
			ans.push_back(i);
	return ans;
}

int main(void)
{
	vector<int> ans = solution(7);
	
	for(auto& e : ans)
		cout << e << " ";
	cout << endl;
	return	0;
}
