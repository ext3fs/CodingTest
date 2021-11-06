//programmers 2개이하로 다른비트(77885)
#include <iostream>
#include <vector>
using namespace std;

/*
   1. 짝수이면 답은 n+1
   2. 홀수이면 
        n       mask       답 
      10111  +  00100  =  11011 

   cf) n		= 00010111
       ~n		= 11101000
       n+1		= 00011000
       ~n & (n+1)	= 00001000 <- mask
       mask - (mask>>1) = 00000100
 */

vector<long long> solution(vector<long long> num)
{
	for(auto& n : num)
	{
		long long mask = ~n & (n+1);
		n = n + mask - (mask>>1);
		/*
		if((n & 1L) == 0){
			++n;
			continue;
		}
	
		long long mask = 1;

		while(n & mask)
			mask <<= 1;

		n += mask >> 1;
		*/
	}
	return num;
}

int main(void)
{
	vector<long long> v = {2,7};
	vector<long long> ans = solution(v);
	
	for(auto& e : ans)
		cout << e << endl;
	return	0;
}
