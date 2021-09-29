//programmers 42895
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/*
N1 : 5	 
N2 : 55		, N1 @ N1
N3 : 555	, N1 @ N2, N2 @ N1 
N4 : 5555	, N1 @ N3, N2 @ N2, N3 @ N1
N5 : 55555	, N1 @ N4, N2 @ N3, N3 @ N2, N4 @ N1

중복되는 값은 저장할 필요가 없다
결과가 0인것은 저장할 필요가 없다
결과가 -a 인것은 다른계산에서 반드시 +a가 나온다
*/

vector<unordered_set<int>> dp;
int _number;

int calc(int a, int b, int op)
{
	if(op == 0)
		return a + b;
	if(op == 1)
		return a * b;
	if(op == 2)
		return a - b;
	return a / b;
}

bool find_number(int idx)
{
	int a=1, b=idx-1;

	while(b > 0)
	{
		for(auto& lhs : dp[a])
		{
			for(auto& rhs : dp[b])
			{
				for(int i=0; i<4; ++i)
				{
					int val = calc(lhs, rhs, i);
				
					if(val == _number)
						return true;
					
					if(val > 0)
						dp[idx].insert(val);
				}
			}	
		}
		++a; --b;
	}
	return false;
}

int solution(int N, int number)
{
	_number = number;
	dp.resize(9);

	for(int i=1; i<9; ++i)
	{
		string str(i,'0'+N);
		int val = stoi(str);

		if(val == number || find_number(i))
			return i;
		
		dp[i].insert(val);
	}
	return -1;
}

int main(void)
{
	//for(auto& e : ans)
	//	cout << e << endl;
	int ans = solution(5, 12);
	cout << "ans = " << ans << endl;
	return	0;
}

