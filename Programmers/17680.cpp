//programmers 캐시(17680)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
	if(cacheSize == 0)
		return cities.size() * 5;

	vector<string> v;
	int ans=0;

	for(string& city : cities)
	{
		for(char& ch : city)
			ch = tolower(ch);		

		auto iter = find(v.begin(),v.end(),city);

		if(iter == v.end())
		{
			if(v.size() == cacheSize)
				v.erase(v.begin());	
			
			v.push_back(city);
			ans += 5;
			continue;
		}

		v.erase(iter);
		v.push_back(city);
		++ans;
	}
	return ans;
}

int main(void)
{
	vector<string> v = {"Jeju", "Pangyo", "NewYork", "newyork"};
	int ans = solution(2,v);
	cout << "ans = " << ans << endl;
	return	0;
}
