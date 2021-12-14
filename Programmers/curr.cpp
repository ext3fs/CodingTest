//programmers 모두0으로만들기(76503)
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(vector<string> lines)
{
	vector<pair<double,double>> v;
    
	for(auto& line : lines){
		stringstream ss(line);
		string tmp,s1,s2;
		ss >> tmp >> s1 >> s2;

		double h = stod(s1.substr(0)) * 60 * 60;
		double m = stod(s1.substr(3)) * 60; 
		double s = stod(s1.substr(6));
		double end = h + m + s;
		v.push_back({end-stod(s2)+0.001, end});
        
        //cout << end << " = " << sec << endl;
        //cout << t.back().first << "," << t.back().second << endl;
	}        
        
	int ans = 0;
	for(int i=0; i<v.size(); ++i)
	{
		int cnt = 1;
		double endPoint = v[i].second + 1; 	

		for(int j=i+1; j<v.size(); ++j)
			if(v[j].first < endPoint)
				++cnt;
        
		ans = max(ans,cnt);
        }
	return ans;
}

int main(void)
{
	vector<string> v = {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"};
	int ans = solution(v);
	cout << ans << endl;	
	return	0;
}
