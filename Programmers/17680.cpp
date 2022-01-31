//programmers 캐시(17680)
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//list -> find() 가능

int solution(int cacheSize, vector<string> cities)
{
	if(cacheSize == 0)
		return cities.size() * 5;

	int ans = 0;
	list<string> lst;

	for(string& city : cities)
	{
		for(char& ch : city)
			ch = tolower(ch);

		auto it = find(lst.begin(), lst.end(), city);

		if(it == lst.end())
		{
			if(lst.size() == cacheSize)
				lst.pop_front();	
		
			ans += 5;		
			lst.push_back(city);
			continue;
		}

		++ans;
		lst.erase(it);
		lst.push_back(city);
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
