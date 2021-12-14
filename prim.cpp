//backjun - 별자리만들기(4386) 
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using pdi = pair<double,int>;

double getDist(const pair<double,double>& a, const pair<double,double>& b){
	return hypot(a.first - b.first, a.second - b.second);	
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<pair<double,double>> v(n);
	for(int i=0; i<n; ++i)
		cin >> v[i].first >> v[i].second; 	
	
	//prim
	vector<bool> visit(n);
	priority_queue<pdi,vector<pdi>,greater<pdi>> q;	
	double sum = 0;
	
	q.push({0,0});
	while(!q.empty())
	{
		double dist = q.top().first;
		int curr = q.top().second;
		q.pop();
	
		if(visit[curr])
			continue;
		
		visit[curr] = true;
		sum += dist;
		
		for(int i=0; i<n; ++i)
			if(!visit[i])
				q.push({getDist(v[curr],v[i]),i});
	}

	cout << fixed;
	cout.precision(2);
	cout << sum << '\n';
	return 0;
}
