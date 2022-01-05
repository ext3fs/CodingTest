//programmers 42586
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> pro, vector<int> sp)
{
	//remain day calc
	for(size_t i=0; i<pro.size(); ++i)
		pro[i] = (99 - pro[i])/sp[i] + 1;		

	int curr_day = pro[0];
	int cnt = 1;	
	vector<int> ans;

	for(size_t i=1; i<pro.size(); ++i)
	{
		if(pro[i] > curr_day)
		{
			ans.push_back(cnt);
			curr_day = pro[i];
			cnt = 1;
			continue;
		}

		++cnt;
	}

	ans.push_back(cnt);
	return ans;
}


int main(void)
{
	vector<int> pro = {93,30,55};
	vector<int> sp = {1,30,5};
	//vector<int> pro = {95,90,99,99,80,99};
	//vector<int> sp = {1,1,1,1,1,1};
	vector<int> ans = solution(pro,sp);

	for(int val : ans)
		cout << val << endl;
	return	0;
}

