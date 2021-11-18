//backjun 수찾기(1920) 
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

int readInt(char*& ptr)
{
	int ret=0, flag=1;
	char ch = *ptr++;

	if(ch == '-')
		flag = -1, ch = *ptr++;

	while(isdigit(ch))
		ret = ret * 10 + ch - '0', ch = *ptr++;

	return 	flag * ret;
}

int bSearch(vector<int>& v, int val)
{
	int start=0, end=v.size()-1;

	while(end >= start)
	{
		int mid = (end + start)/2;

		if(v[mid] < val)
			start = mid + 1;
		else if(v[mid] > val)
			end = mid - 1;
		else
			return 1;
	}

	return 0;
}

int main(void)
{
	struct stat st;
	fstat(0, &st);
	char* ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int n = readInt(ptr);
	vector<int> v(n);
	for(int i=0; i<n; ++i)
		v[i] = readInt(ptr); 
	sort(v.begin(),v.end());

	int m = readInt(ptr);
	for(int i=0; i<m; ++i)
		printf("%d\n", bSearch(v,readInt(ptr)));

	return 0;	
}
