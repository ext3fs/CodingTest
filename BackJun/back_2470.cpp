//backjun 두용액(2470) 
#include <algorithm>
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
	int ar[n];
	for(int i=0; i<n; ++i)
		ar[i] = readCin(ptr); 
	sort(ar, ar+n);

	/*
	int n;
	cin >> n;
	vector<int> ar(n);
	for(int i=0; i<n; ++i)
		cin >> ar[i]; 
	sort(ar.begin(),ar.end());

	for(int i=0; i<n; ++i)
		cout << ar[i] << ' ';
	cout << endl;
	*/

	int start=0, end=n-1;
	int v1, v2, minV=INT32_MAX;
	while(start != end)
	{
		int val = ar[start] + ar[end];

		if(abs(val) < minV){
			v1 = ar[start];
			v2 = ar[end];
			minV = abs(val);
		}

		if(val < 0)
			++start;				
		else if(val > 0)
			--end;
		else
			break;
	}

	printf("%d %d\n",v1,v2);
	return 0;	
}
