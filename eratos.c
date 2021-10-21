#include <iostream>
#include <cmath>

using namespace std;

int solution(int n)
{
	int answer = 0;
	int cnt = sqrt(n) +1;
	char* ar = (char*)calloc(n+1,sizeof(char));

	for(int i=2; i<=cnt; ++i)
	{
		if(ar[i] == 0)
		{
			for(int j=i+i; j<=n; j+=i)
				ar[j]	= 1;
		}		
	}

	for(int i=2; i<=n; ++i)
		if(ar[i] == 0)
			++answer;
	
	return answer;
}

int main(void)
{
	cout << solution(99999) << endl;
	return (0);
}

