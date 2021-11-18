//backjun 수들의합2(2003) 
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

int readCin(char*& ptr)
{
	int ret=0, flag=1;
	char ch = *ptr++;

	if(ch == '-')
		flag = -1, ch = *ptr++;

	while(isdigit(ch))
		ret = ret * 10 + ch - '0', ch = *ptr++;

	return 	flag * ret;
}

int main(void)
{
	struct stat st;
	fstat(0, &st);
	char* ptr = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int n = readCin(ptr);
	int m = readCin(ptr);

	int v[n];
	for(int i=0; i<n; ++i)
		v[i] = readCin(ptr); 

	/*
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i]; 
	*/

	int start = 0, end = 0;
	int sum = 0, ans = 0;
	while(1)
	{
		if(end == n && sum < m)
			break;

		if(sum < m)
			sum += v[end++];		
		else if(sum > m)
			sum -= v[start++];
		else
			++ans, sum -= v[start++];
	}

	cout << ans << '\n';
	return 0;	
}
