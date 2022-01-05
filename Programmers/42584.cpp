//programmers 42584
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//몇번째에 가격이 떨어지냐? == 몇초간 유지되었나?

vector<int> solution(vector<int> price)
{
	vector<int> ans(price.size());
	stack<int> stk;

	for(int i=0; i<price.size(); ++i)
	{
		while(!stk.empty())
		{
			int idx = stk.top();
			
			if(price[idx] <= price[i])
				break;
			
			ans[idx] = i - idx; 
			stk.pop();		
		}

		stk.push(i);
	}

	while(!stk.empty())
	{
		ans[stk.top()] = price.size() - 1 - stk.top();
		stk.pop();
	}

	return ans;
}

int main(void)
{
	vector<int> v = {1, 2, 3, 2, 3};
	vector<int> ans = solution(v);

	for(auto& e : ans)
		cout << e << endl;
	return	0;
}

