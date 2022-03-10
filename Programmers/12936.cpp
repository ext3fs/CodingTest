//programmers 줄서는순서(12936)
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, long long k)
{
    vector<long> fac(n,1);
    for(int i=1; i<n; ++i)
        fac[i] = i*fac[i-1];
   
    vector<int> v(n);
    for(int i=0; i<n; ++i)
    	v[i] = i+1;
 
    --k;//순서를 0번째부터라고 생각하면됨 
    vector<int> ans;
    while(n--)
    {
        long share = k/fac[n];	
        k = k%fac[n];
        ans.push_back(v[share]);
        v.erase(v.begin()+share);
    }
    return ans;
}

int main(void)
{
	vector<int> ans = solution(4,6);

	cout << " ans = " << endl;
	for(auto& e : ans)
		cout << e << ' ';
	cout << endl;
	return	0;
}
