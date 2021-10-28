//programmers 42884
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes)
{
	int ans = 0;
	int pos = -30001;

	sort(routes.begin(), routes.end(), comp);

	for(auto& v : routes)
		cout << v[0] << " : " << v[1] << endl;

	for(size_t i=0; i<routes.size(); ++i)
	{
		//pos > routes[i][1]은 필요없다.. sort로서 항상 보장
		if(pos < routes[i][0]){
			++ans;
			//범위를 벗어나면 바로 pos 교체.. 
			//앞의pos는 만족하는데,뒤의pos를 만족하지 못하는 경우는 sort에 의해 앞에왔을것 
			pos = routes[i][1];
		}	
	}
	return ans;
}

int main(void)
{
	vector<vector<int>> routes = {{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}};
		
	int ans = solution(routes);
	cout << "ans = " << ans << endl;
	return	0;
}

