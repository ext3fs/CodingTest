//backjun - 구간합구하기(2042) 
#include <iostream>
#include <vector>
using namespace std;

struct fwTree
{
	vector<int64_t> v, tree;
	
	fwTree(vector<int64_t>& src)
	{
		v.resize(src.size());
		tree.resize(src.size());

		for(size_t i=1; i<src.size(); ++i)
			update(i, src[i]);		
	}

	void update(int idx, int64_t val)
	{
		int64_t diff = val - v[idx];
		
		v[idx] = val;
		while(idx < tree.size()){
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}

	int64_t sum(int idx)
	{
		int64_t ret = 0;

		while(idx > 0){
			ret += tree[idx];
		       	idx -= (idx & -idx);
		}
		return ret; 
	}

	void show()
	{
		for(size_t i=1; i<v.size(); ++i)
			cout << v[i];
		cout << endl;	

		size_t n = 2;
		while(n/2 < tree.size())
		{
			for(size_t i=n/2; i<tree.size(); i+=n)
				cout << tree[i] << ' ';
			cout << endl;
			n *= 2;
		}
	}	
};


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int n,m,k;
	cin >> n >> m >> k;
	m += k;

	vector<int64_t> v(n+1);
	for(int i=1; i<=n; ++i)
		cin >> v[i];

	fwTree tree(v);
	int64_t cmd,a,b;
	while(m--)
	{
		cin >> cmd >> a >> b;

		if(cmd == 1)
			tree.update(a,b);
		else
			cout << tree.sum(b) - tree.sum(a-1) << '\n';	
	}	
	return 0;
}
