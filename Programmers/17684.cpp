//programmers 압축(17684)
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//stable sort

struct Node{
	string_view file;
	string head;
	int num;	
};

int getNumberIdx(string_view str)
{
	for(size_t i=0; i<str.size(); ++i)
		if(isdigit(str[i]))
			return i;
	return 0;		
}

string makeLower(string&& str)
{
	for(size_t i=0; i<str.size(); ++i)
		str[i] = tolower(str[i]);
	return str;	
}

bool cmp(const Node& a, const Node& b)
{
	if(a.head == b.head)
		return a.num < b.num;
	return a.head < b.head;
}

vector<string> solution(vector<string> files)
{
	vector<Node> v(files.size());
	
	for(size_t i=0; i<files.size(); ++i)
	{
		int idx = getNumberIdx(files[i]);

		v[i].file = files[i];
		v[i].head = makeLower(files[i].substr(0,idx));
		v[i].num = stoi(files[i].substr(idx));
	}
	stable_sort(v.begin(), v.end(), cmp);
	
	vector<string> ans(files.size());
	for(size_t i=0; i<files.size(); ++i)
		ans[i] = v[i].file;
	return ans;
}

int main(void)
{
	vector<string> v = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
	vector<string> ans = solution(v);
	
	for(auto& e : ans)
		cout << e << endl;
	return	0;
}
