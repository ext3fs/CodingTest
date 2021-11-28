//backjun 9184(신나는 함수실행) 
#include <cstdio>

int dp[21][21][21];

auto fn = [](int a, int b, int c){
	return dp[a][b][c];	
};

int w(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
    		return 1;

	if(a > 20 || b > 20 || c > 20)
    		return fn(20, 20, 20);

	if(a < b && b < c)
		return fn(a, b, c-1) + fn(a, b-1, c-1) - fn(a, b-1, c);

	return fn(a-1, b, c) + fn(a-1, b-1, c) + fn(a-1, b, c-1) - fn(a-1, b-1, c-1);
}

int main(void)
{
	for(int i=0; i<21; ++i)
		for(int j=0; j<21; ++j)
			for(int k=0; k<21; ++k)
				dp[i][j][k] = w(i,j,k);		
	
	int a, b, c;
	while(1)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));	
	}
	return 0;	
}
