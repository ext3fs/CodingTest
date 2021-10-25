#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
using namespace std;

/*
   this is wrong.. show next version
 */

struct TrieNode
{
	bool isEnd = false;
	unordered_map<char,unique_ptr<TrieNode>> child;

	void insert(string_view str, int idx=0)
	{
		if((size_t)idx == str.size())
			return;
		
		if((size_t)idx == str.size()-1)
			isEnd = true;

		if(child.find(str[idx]) == child.end())
			child.insert({str[idx], make_unique<TrieNode>()});
			
		child[str[idx]]->insert(str, idx+1);
	}

	bool find(string_view str, int idx=0)
	{
		if((size_t)idx == str.size())
			return false;

		if(child.find(str[idx]) == child.end())
			return false;
			
		if(isEnd && (size_t)idx == str.size()-1)
			return true;

		return child[str[idx]]->find(str, idx+1);
	}

	void show()
	{
		static string str;

		for(auto& e : child){
			str.push_back(e.first);
			if(isEnd)
				cout << "str = "<< str << endl;
			e.second->show();
			str.pop_back();
		}
	}
};

int main()
{
	TrieNode root;
	
	string s = "dafaf";
	root.insert(s);
	root.insert("abc");
	root.insert("bc");
	root.insert("dzz");
	root.insert("dza");
	root.show();

	string str = "dzz";
	cout << str << " find? = " << root.find(str) << endl;
	return 0;
}
