//programmers 다단계칫솔판매(77486)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string,string> mp;

void putGain(unordered_map<string,int>& money, string& seller, int gain)
{
	//cout << seller << " " << gain << endl;
	money[seller] += gain - gain/10;
	gain /= 10;

	if(gain == 0 || mp[seller] == "-")
		return;

	putGain(money, mp[seller], gain);
}

vector<int> solution(vector<string> name, vector<string> parent, vector<string> seller, vector<int> gain)
{
	mp.clear();
	unordered_map<string,int> money;
	for(int i=0; i<name.size(); ++i){
		mp.insert({name[i],parent[i]});
		money.insert({name[i],0});
	}
	
	for(int i=0; i<seller.size(); ++i)
		putGain(money,seller[i],gain[i]*100);	
	
	vector<int> ans;
	for(string& s : name)
		ans.push_back(money[s]);
	return ans;
}

int main(void)
{
	vector<string> name = {"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"};
	vector<string> parent = {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"};
	vector<string> seller = {"young", "john", "tod", "emily", "mary"};
	vector<int> gain = {12, 4, 2, 5, 10};

	vector<int> ans = solution(name,parent,seller,gain);
	for(int i : ans)
		cout << i << " ";
	cout << endl;	
	return	0;
}

