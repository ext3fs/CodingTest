//programmers 72412
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
	unordered_map<string,vector<int>> info_map;
    
	for(auto& s : info)
	{
    	string str;
    	stringstream ss(s);
		vector<string> tok;

		while(ss >> str)
			tok.push_back(str);
		
		/*for(int i=0; i<16; ++i)
		{
			vector<string> key(4,"-");

			for(int j=0; j<4; ++j)
				if(i & (1<<j))
					key[j] = tok[j];
			
			info_map[key[0]+key[1]+key[2]+key[3]].push_back(stoi(tok[4]));
		}*/

		//bitmask_combination	
		for(int mask=0; mask<16; ++mask)
		{
			string key = "", all = "-";

			for(int i=0; i<4; ++i)
				key += (mask & (1<<i)) ? all : tok[i];
			
			info_map[key].push_back(stoi(tok[4]));
		}
	}

	for(auto& e : info_map)
		sort(e.second.begin(), e.second.end());

	for(auto& q : query)
	{
    	stringstream ss(q);
		string tok[4], str;
		int score;

		ss >> tok[0] >> str >> tok[1] >> str >> tok[2] >> str >> tok[3] >> score; 	
        str = tok[0] + tok[1] + tok[2] + tok[3];
        
		auto& v = info_map[str];
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), score));
	}
	
    return answer;
}

int main(void)
{
			
	vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210",
						   "python frontend senior chicken 150","cpp backend senior pizza 260",
						   "java backend junior chicken 80","python backend senior chicken 50"};
	vector<string> query = {"java and backend and junior and pizza 100",
							"python and frontend and senior and chicken 200",
							"cpp and - and senior and pizza 250","- and backend and senior and - 150",
							"- and - and - and chicken 100","- and - and - and - 150"};
	vector<int> v = solution(info, query);

	for(auto e : v)
		cout << e;
	cout << endl;	
	return 0;
}
