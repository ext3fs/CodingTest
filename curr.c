#include <vector>
#include <iostream>

using namespace std;

int ar[] = {1,2,3};

void Permutation(int depth, int n, int r)
{
	if(depth == r)
	{	
		for(int i=0; i<r; ++i)
			cout << ar[i] << " ";
		cout << endl;
		return;	
	}	
	
	for(int i=depth; i<n; ++i)
	{
		swap(ar[depth], ar[i]);
		Permutation(depth+1, n, r);
		swap(ar[depth], ar[i]);
	}
}

int	main(void)
{
	Permutation(0, 3, 2);	
	return	0;
}

