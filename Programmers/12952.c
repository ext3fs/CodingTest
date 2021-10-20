//programmers N-Queen(12952)
#include <iostream>
#include <vector>
using namespace std;

/*
   1. dfs는 완전탐색의 트리구조
   2. back tracking(가지치기)
   3. col[i] -> i행의 colum값
*/

vector<int> col;
int succ;

bool isVaild(int x, int y)
{
	for(int i=0; i<x; ++i)
	{
		if(y == col[i])
			return false;

		//각각 x,y값들의 차이가 같으면 사선에 있다  
		//x는 i보다 항상 크다, y는 윗열의 colum값보다 작을수 있다.. 			
		if(x - i == abs(y - col[i]))
			return false;			
	}
	return true;	
}

void dfs(int depth, int n)
{
	if(depth == n){
		++succ;
		return;
	}

	for(int j=0; j<n; ++j)
	{
		if(isVaild(depth,j)){
			col[depth] = j; 
			dfs(depth+1,n);
			//col[depth] = -1; 
		}
	}
}

int solution(int n)
{
	col.resize(n,-1);
	succ = 0;
	dfs(0, n);
	return succ;
}

int main(void)
{
	int ret = solution(4);
	cout << "ans = " << ret << endl;
	return	0;
}
