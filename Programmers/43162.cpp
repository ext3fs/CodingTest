//programmers 43162
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> parent;

int find_root(int idx)
{
	if(idx == parent[idx])
		return idx;
	return parent[idx] = find_root(parent[idx]);	
}

void union_node(int a, int b)
{
	a = find_root(a);
	b = find_root(b);

	//인덱스 높은노드가 더 낮은 루트노드 가지고 있을수도 있음..
	if(b > a)
		parent[b] = a;
	else	
		parent[a] = b;
}

int solution(int n, vector<vector<int>> mat)
{
	parent.resize(n);
	for(int i=0; i<n; ++i)
		parent[i] = i;
	
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			if(mat[i][j])
				union_node(i,j);

	//union_node() 하면 최상위 노드의 parent[]만 업데이트 됨..
	//그래서, 최종적으로 find_root() 해줘야함..			
	unordered_set<int> st;
	for(int i=0; i<n; ++i)
		st.insert(find_root(i));
	return st.size();
}

int main(void)
{
	vector<vector<int>> v = {{1,0,0,0,0}, 
				 {0,1,0,0,1}, 
				 {0,0,1,1,0},
				 {0,0,0,1,1},
				 {0,0,0,0,1}};

	int ans = solution(5,v);
	cout << "ans = " << ans << endl;
	return	0;
}

