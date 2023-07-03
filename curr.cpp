#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
void show(T& obj)
{
	for(int i : obj)
		cout << i << " ";
	cout << endl;

	//cout << obj.first << " : " << obj.second << endl;
}

struct cmp
{
	bool operator()(vector<int>& a, vector<int>& b){
		return a[0] > b[0];
	}	
};

int main(void)
{
	priority_queue<vector<int>,vector<vector<int>>,cmp> q;
	vector<int> a = {1,2};
	vector<int> b = {2,3};

	q.push(a);
	q.push(b);
	
	while(q.size())
		show(q.top()), q.pop();

	return 0;
}
