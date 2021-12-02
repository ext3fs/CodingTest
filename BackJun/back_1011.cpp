//backjun - fly me to the AlphaCentauri(1011) 
#include <iostream>
#include <cmath>
using namespace std;

/*
	center	sequence	dist(center^2)	cnt(center*2 - 1)
	2	    1 2 1	4		3	
	3	  1 2 3 2 1	9		5
	4	1 2 3 4 3 2 1	16		7	
*/

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	
	for(int i=0; i<n; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		int dist = b - a;
		int center = sqrt(dist);
		int ans = center*2 - 1;
		
		dist -= center*center;
		ans += dist/center;

		if(dist%center)
			++ans;

		cout << ans << endl;		
	}	
	return 0;
}
