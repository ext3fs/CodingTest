//backjun - 분수찾기(1193) 
#include <cstdio>

int main(void)
{
	int n;
	scanf("%d", &n);

	int i=0, j=0;
	bool isUp = true;

	while(--n)
	{
		if(isUp)
		{
			if(i == 0)
				++j, isUp = false;
			else
				--i, ++j;
					
		}
		else
		{
			if(j == 0)
				++i, isUp = true;
			else
				++i, --j;
		}
	}
	
	printf("%d/%d\n", i+1, j+1);
	return 0;
}
