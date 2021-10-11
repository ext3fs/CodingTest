//programmers 43105
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> tri)
{
	/*for(size_t i=0; i<tri.size(); ++i){
		for(size_t j=0; j<tri[i].size(); ++j)
			cout << tri[i][j] << " ";
		cout << endl;	
	}*/

	for(int i=tri.size()-2; i>=0; --i)
		for(int j=0; j<tri[i].size(); ++j)
			tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);

	return tri[0][0];
}

int main(void)
{
	vector<vector<int>> routes = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
		
	int ans = solution(routes);
	cout << "ans = " << ans << endl;
	return	0;
}

