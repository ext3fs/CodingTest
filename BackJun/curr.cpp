//backjun - 구간합구하기(2042) 
#include <iostream>
using namespace std;

int main(void)
{
	int a,b,v;
	cin >> a >> b >> v;

	int oneDayDist = a - b;
	int day = (v-a)/oneDayDist +1;
	int rest = (v-a)%oneDayDist + a;
	
	int day = (v-b)/(a-b);

	cout << day << '\n';	
	return 0;
}
