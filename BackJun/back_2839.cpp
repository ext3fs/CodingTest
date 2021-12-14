//backjun - 설탕배달(2839) 
#include <cstdio>

int sol(int n)
{
	for(int i=0; i<=n/3; ++i)
		if((n-3*i)%5 == 0)
			return i + (n-3*i)/5;
		
	return -1;		
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n",sol(n));
	return 0;
}
