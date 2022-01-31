//programmers 양궁대회(92342)
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
vector<int> api;
vector<int> tv;
int maxVal;

void compute(int cnt)
{
	//make ray
	vector<int> ray(11);
	for(int i : tv){
		ray[i] = api[i] + 1;
	       	cnt -= ray[i];
	}
	
	if(cnt < 0)
		return;	
	else
		ray[10] = cnt;

	//score compute
	int a = 0, r = 0;
	for(int i=0; i<11; ++i)
	{
		if(ray[i] + api[i] == 0)
			continue;

		if(ray[i] > api[i])
			r += 10 - i;
		else
			a += 10 - i;
	}

	//maxVal
	int val = r - a;
	if(val == maxVal)
	{
		for(int i=10; i>=0; --i)
		{
			if(ray[i] == ans[i])
				continue;

			if(ray[i] > ans[i])
				ans = move(ray);
			return;
		}
	}
	
	if(val > maxVal){
		maxVal = val;
		ans = move(ray);
	}
}

void combi(int r, int start)
{
	if(tv.size())
		compute(r);	
	
	if(tv.size() == r)
		return;

	for(int i=start; i<10; ++i){
		tv.push_back(i);
		combi(r,i+1);
		tv.pop_back();
	}
}

vector<int> solution(int n, vector<int> info)
{
	ans.clear();
	api = move(info);
	maxVal = INT32_MIN;
	combi(n,0);
	
	if(maxVal <= 0)
		return {-1};
	return ans;
}

int main(void)
{
	vector<int> v = {2,1,1,1,0,0,0,0,0,0,0};
	vector<int> ans = solution(5,v);

	cout << maxVal << endl;
	for(int i : ans)
		cout << i << " ";
	cout << endl;
	return	0;
}
