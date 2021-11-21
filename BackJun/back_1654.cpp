//backjun 랜선 자르기(1654) 
#include <iostream>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

int readInt(char*& ptr)
{
	int ret=0;
	char ch = *ptr++;

	while(isdigit(ch))
		ret = ret * 10 + ch - '0', ch = *ptr++;

	return	ret;
}

int main(void)
{
	struct stat st;
	fstat(0, &st);
	char* ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int k = readInt(ptr);
	int n = readInt(ptr);
	int ar[k];
	long long start = 1, end = 1;
	long long ret = 0;

	for(int i=0; i<k; ++i){
		ar[i] = readInt(ptr);
		end = max(end,(long long)ar[i]);
	}	

	while(end >= start)
	{
		long long cnt = 0;
		long long mid = (start + end)/2;

		for(int i=0; i<k; ++i)
			cnt += ar[i]/mid;			

		if(cnt < n)
			end = mid - 1;	
		else
			ret = mid, start = mid + 1;
	}
	printf("%lld\n", ret);
	return 0;	
}
