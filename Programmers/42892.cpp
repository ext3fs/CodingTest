//programmers 길찾기게임(42892)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int no, x, y;
	Node *left, *right;
};
       	
bool cmp(const Node* a, const Node* b){
	return a->y < b->y;
}

Node* dnc(vector<Node*>& v)
{
	if(v.size() == 0)
		return nullptr;

	Node* root = *max_element(v.begin(),v.end(),cmp);		
	vector<Node*> left;
	vector<Node*> right;

	for(auto ptr : v)
	{
		if(ptr->x < root->x)
			left.push_back(ptr);
		else if(ptr->x > root->x)
			right.push_back(ptr);
	}
		
	root->left = dnc(left);	
	root->right = dnc(right);	
	return root;
}

void preOrder(Node* root, vector<int>& ans)
{
	if(root == nullptr)
		return;

	ans.push_back(root->no);
	preOrder(root->left, ans);
	preOrder(root->right, ans);
}

void postOrder(Node* root, vector<int>& ans)
{
	if(root == nullptr)
		return;

	postOrder(root->left, ans);
	postOrder(root->right, ans);
	ans.push_back(root->no);
}

vector<vector<int>> solution(vector<vector<int>> info)
{
	vector<Node> node(info.size());
	vector<Node*> v(info.size());

	for(int i=0; i<info.size(); ++i){
		node[i] = {i+1, info[i][0], info[i][1]};
		v[i] = &node[i];
	}

	Node* root = dnc(v);
	vector<vector<int>> ans(2);
	preOrder(root, ans[0]);
	postOrder(root, ans[1]);
	return ans;
}

int main(void)
{
	vector<vector<int>> vv = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
	vector<vector<int>> ans = solution(vv);

	for(auto& v : ans){
		for(auto& i : v)
			cout << i << ' ';
		cout << endl;
	}
	return	0;
}
