//programmers 압축(17684)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
	int idx = 0;
	unordered_map<string,int> dic;
	for(char ch='A'; ch<='Z'; ++ch)
		dic.insert({string(1,ch),++idx});
    
	vector<int> ans;
	for(int i=0; i<msg.size();)
    	{
        	string tmp = "";
		
		for(int j=i; j<msg.size(); ++j)
		{
			tmp.push_back(msg[j]);

			if(dic.find(tmp) == dic.end()){
				dic.insert({tmp,++idx});
				tmp.pop_back();
				break;
			}
        	}
        
		ans.push_back(dic.find(tmp)->second);
		i += tmp.size();
	}

	return ans;
}

int main(void)
{
	string s = "KAKAO";
	vector<int> ans = solution(s);
	
	for(auto& e : ans)
		cout << e << endl;
	return	0;
}
