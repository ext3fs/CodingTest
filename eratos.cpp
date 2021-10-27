#include <iostream>
#include <vector>
using namespace std;

/*
  시간복잡도는 amortized O(n)

  1. 모든 isPrime을 true로 
  2. 0과 1은 소수가 아니다
  3. 현재 소수라고 표시된 놈의 배수만 소수가 아니다로 표시   
*/

int eratos(int n)
{
	vector<bool> isPrime(n+1,true);
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2; i*i<=n; ++i)
	{
		if(isPrime[i])
		{
			for(int j=i+i; j<=n; j+=i)
				isPrime[j] = false;
		}		
	}

	int cnt = 0;
	for(bool b : isPrime)
		if(b)
			++cnt;	
	return cnt;
}

int main(void)
{
	cout << eratos(9) << endl;
	return (0);
}

