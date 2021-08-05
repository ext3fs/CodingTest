//backjun 11404
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 

	int n,m,a,b,c;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int>(n,1e9));

	for(int i=0; i<m; ++i){
		cin >> a >> b >> c;
	  	v[a-1][b-1] = min(v[a-1][b-1], c);	
	}
	
	//floyd warshall
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
					
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			if(i==j || v[i][j] == 1e9)
				cout << "0 ";
			else
				cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
