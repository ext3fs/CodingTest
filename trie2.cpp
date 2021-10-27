#include <iostream>
#include <vector>
#include <optional>
using namespace std;

struct Node
{
	bool isEnd;
	vector<optional<Node>> child;

	explicit Node(){
		isEnd = false;
		child.resize(26);
	}

	//~Node() = default;
	//Node(const Node& src) = default;
	//Node& operator=(const Node& rhs) = default;
	//Node(Node&& src) = default;
	//Node& operator=(Node&& rhs) = default;

	void insert(string_view str)
	{
		auto curr = this;

		for(size_t i=0; i<str.size(); ++i){
			int idx = str[i] - 'a';
			if(curr->child[idx].has_value() == false)
				curr->child[idx] = Node();
			curr = &(curr->child[idx].value());	
		}

		curr->isEnd = true;
	}

	bool find(string_view str)
	{
		auto curr = this;

		for(size_t i=0; i<str.size(); ++i){
			int idx = str[i] - 'a';
			if(curr->child[idx].has_value() == false)
				return false;
			curr = &(curr->child[idx].value());	
		}

		if(curr->isEnd)
			return true;
		return false;	
	}
	
	void show()
	{
		static string str;

		if(isEnd)
			cout << str << endl;

		for(int i=0; i<26; ++i){
			if(child[i].has_value()){
				str.push_back(i + 'a');
				child[i].value().show();	
				str.pop_back();	
			}
		}
	}
};

int main()
{
	Node a;
	a.insert("aaa");
	a.insert("ab");
	a.insert("abc");
	a.insert("zb");
	a.show();
	cout << endl;

	Node b(a);
	b.insert("zzb");
	b.show();
	cout << endl;

	a = b;
	a.show();
	cout << endl;

	Node c(move(b));
	c.show();
	cout << endl;

	string str = "ab";
	cout << "find = "<< str << " -> "<< c.find(str) << endl;	
	return 0;
}
