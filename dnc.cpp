//backjun 색종이만들기(2630) 
#include <iostream>
#include <vector>
using namespace std;

int white, blue;

void dnc(vector<vector<char>>& vv, int n, int x, int y)
{
	int cnt = 0;
	for(int i=x; i<x+n; ++i)
		for(int j=y; j<y+n; ++j)
			cnt += vv[i][j];

	if(cnt == 0){
		++white;
		return;
	}		
	
	if(cnt == n*n){
		++blue;
		return;
	}
	
	n /= 2;
	dnc(vv, n, x,   y);
	dnc(vv, n, x,   y+n);
	dnc(vv, n, x+n, y);
	dnc(vv, n, x+n, y+n);
}

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	string str;
	getline(cin,str);
	int n = stoi(str); 

	vector<vector<char>> vv(n,vector<char>(n));
	for(int i=0; i<n; ++i)
	{
		getline(cin,str);
		for(int j=0; j<n; ++j)
			vv[i][j] = str[j*2] - '0';
	}

	dnc(vv,n,0,0);
	cout << white << '\n' << blue << '\n';
	return 0;	
}
