//programmers 17687
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  2 | 10
     ----
  2 | 5     -  0
     ----
  2 | 2     -  1
     ----
  2 | 1     -  0
     ----
  2 | 0     -  1
     ----

  10을 2진수로 -> 1010(0이 나올때까지 계속 나누어줌, 나머지의 역순)  
 */

string convt(int n, int val)
{
	static string number = "0123456789ABCDEF";
	string s = "";
	
	while(1)
	{
		s.push_back(number[val%n]);
		val /= n;

		if(val == 0){
			reverse(s.begin(), s.end());
			return s;	
		}
	}
}

string solution(int n, int t, int m, int p)
{
	string s = "";
	for(int i=0; s.size()<t*m; ++i)
		s += convt(n,i);
	
	string ans = "";
	for(int i=p-1; ans.size()<t; i+=m)
		ans.push_back(s[i]);		
	return ans;
}

int main(void)
{
	string ret = solution(16,16,2,2);
	//string ret = solution(2,4,2,1);
	cout << "ans = " << ret << endl;
	return	0;
}
