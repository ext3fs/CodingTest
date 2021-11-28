#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(nullptr);

	int n, m, val, ans=1;
	cin >> n >> m;
	
	priority_queue<int> box;
	for(int i=0; i<n; ++i)
		cin >> val, box.push(val);	
	
	for(int i=0; i<m; ++i)
	{
		cin >> val;
		val = box.top() - val;
		box.pop();
		
		if(val < 0){
			ans = 0;
			break;
		}
	
		if(val)
			box.push(val);
	}

	cout << ans << '\n';	
	return 0;
}
