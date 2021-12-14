//backjun - 구간합구하기(2042) 
#include <iostream>
#include <vector>
using namespace std;

struct SegTree
{
	vector<int64_t> tree;

	SegTree(vector<int64_t>& v){
		tree.resize(v.size()*4);
		init(v, 1, 0, v.size()-1);
	}

	int64_t init(vector<int64_t>& v, int node, int start, int end)
	{
		if(start == end)
			return tree[node] = v[start];
		
		return tree[node] = init(v, node*2, start, (start+end)/2)
					+ init(v, node*2+1, (start+end)/2+1, end);	
	}

	/*
	void update(int node, int start, int end, int idx, int64_t diff)
	{
		if(idx < start || idx > end)
			return;
		
		tree[node] += diff;

		if(start != end){
			update(node*2, start, (start+end)/2, idx, diff);
			update(node*2+1, (start+end)/2+1, end, idx, diff);	
		}
	}
	*/

	int64_t update(int node, int start, int end, int idx, int64_t val)
	{
		if(idx < start || idx > end)
			return tree[node];
	
		if(start == end)			
			return tree[node] = val;

		return tree[node] = update(node*2, start, (start+end)/2, idx, val)
					+ update(node*2+1, (start+end)/2+1, end, idx, val);	
	}

	int64_t sum(int node, int start, int end, int left, int right)
	{
		if(end < left || start > right)
			return 0;
		
		if(left <= start && end <= right)
			return tree[node];
			
		return sum(node*2, start, (start+end)/2, left, right)
					+ sum(node*2+1, (start+end)/2+1, end, left, right);	
	}

	void show()
	{
		size_t i=1, n=2;

		while(i < tree.size()){
			cout << tree[i++] << ' ';
			if(n == i)
				n *= 2, cout << endl;
		}
		cout << endl;
	}	
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	m += k;

	vector<int64_t> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i];

	SegTree tree(v);
	int64_t cmd, a, b;
	while(m--)
	{
		cin >> cmd >> a >> b;

		if(cmd == 1)
			tree.update(1, 0, n-1, a-1, b);
		else
			cout << tree.sum(1, 0, n-1, a-1, b-1) << '\n';	
	}
	return 0;
}
