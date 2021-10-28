//programmers 49191
#include <iostream>
#include <vector>
using namespace std;

/*
   1, 모든 전적이 있어야 순위 확정 
   2. 1->2, 2->3 이면 1->3의 전적도 있다고 봄
   3. floyed warall로 위와 같은 경우가 있는지 체크 -> 있다면 전적 만들어 줌
   4. dp table에서 졌다는 전적은 표현할수가 없음
   5. db table에서 대각정보가 나올수 없음, 1->2, 2->1 전적이 있다는것 -> 사이클 
   6. 마지막으로, 이겼다는 전적이 있다면.. 반대로 졌다는 전적도 있다는 것
   7. 대각정보를 다 채우고.. 모든 전적이 있다면 순위 확정  
*/

int solution(int n, vector<vector<int>> results)
{
	vector<vector<int>> dp(n, vector<int>(n));
	for(auto& v : results)
		dp[v[0]-1][v[1]-1] = 1;

	//floyd warshall
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(dp[i][k] && dp[k][j])
					dp[i][j] = 1;

	int ans = 0;
	for(int i=0; i<n; ++i)
	{
		int cnt = 0;

		for(int j=0; j<n; ++j)
			cnt += dp[i][j] + dp[j][i];
		
		if(cnt == n-1)
			++ans;			
	}
	return ans;
}

int main(void)
{
	//vector<vector<int>> v = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};
	//int ret = solution(5,v);
	vector<vector<int>> v = {{1, 2}, {2, 3}};
	int ret = solution(3,v);
	cout << "ret = " << ret << endl;
	return	0;
}


