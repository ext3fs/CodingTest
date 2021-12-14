//backjun - 별자리만들기(4386) 
#include <cstdio>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> group;

double getDist(const pair<double,double>& a, const pair<double,double>& b){
	return hypot(a.first - b.first, a.second - b.second);		
}

int findGroup(int x){
	if(x == group[x])
		return x;
	return group[x] = findGroup(group[x]);	
}

bool unionGroup(int a, int b)
{
	a = findGroup(a);	
	b = findGroup(b);

	if(a < b)
		group[b] = a;	
	else if(a > b)
		group[a] = b;
	else
		return false;

	return true;	
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	group.resize(n);
	for(int i=0; i<n; ++i)
		group[i] = i;	

	vector<pair<double,double>> v(n);	
	for(int i=0; i<n; ++i)
		scanf("%lf%lf", &v[i].first, &v[i].second);

	vector<tuple<double,int,int>> edge;
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			edge.push_back({getDist(v[i],v[j]),i,j});
	sort(edge.begin(), edge.end());

	double sum = 0;
	for(const auto& t : edge)
	{
		if(unionGroup(get<1>(t),get<2>(t)))
		{
			sum += get<0>(t);

			if(--n == 1)
				break;
		}
	}	

	printf("%.2lf\n", sum);
	return 0;
}
