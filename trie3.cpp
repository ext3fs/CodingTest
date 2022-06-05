//programmers 자동완성(17685)
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
using namespace std;

/*
	               root(3)

	     g(3)

	o(2)      u(1)      
	n(1)      i(1) 
	e(1)      l(1) 
	          d(1) 
		
  ans = g(3) + o(2) + n(1) + u(1)  			  
*/

struct TrieNode
{
	int cnt = 0;
	unordered_map<char,unique_ptr<TrieNode>> child;

	void insert(string_view str, int idx=0)
	{
		++cnt;

		if(idx == str.size())
			return;
		
		if(child.find(str[idx]) == child.end())
			child.insert({str[idx],make_unique<TrieNode>()});
			
		child[str[idx]]->insert(str,idx+1);
	}

	int getCntSum()
	{
		if(cnt == 1)
			return 1;
					
		int sum = cnt;

		for(auto& e : child)
				sum += e.second->getCntSum();
		return sum;		
	}
};

int solution(vector<string> words)
{
	TrieNode root;
	
	for(string& word : words)
		root.insert(word);
	
	return root.getCntSum() - root.cnt;
}

int main(void)
{
	//vector<string> v = {"go","gone","guild"};
	//vector<string> v = {"abc","def","ghi","jklm"};
	vector<string> v = {"word","war","warrior","world"};
	int ans = solution(v);
	cout << "ans = " << ans << endl;
	return	0;
}
