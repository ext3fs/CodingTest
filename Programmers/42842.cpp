//programmers 카펫(42842)
#include <iostream>
#include <vector>
using namespace std;

/*
   brown + yellow = width * height
   (width-2)*(height-2) = yellow 
*/

vector<int> solution(int brown, int yellow)
{
	int sum = brown + yellow;	
	
	for(int h=3; ; ++h)
	{
		if(sum%h)
			continue;

		int w = sum/h;
		if((w-2)*(h-2) == yellow)
			return {w,h};
	}
}

int main(void)
{
	vector<int> ans = solution(24,24);
	cout << ans[0] << "," << ans[1] << endl;	
	return	0;
}
