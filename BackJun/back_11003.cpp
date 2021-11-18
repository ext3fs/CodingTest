//backjun 최소값찾기(11003) 
#include <iostream>
#include <deque>
using namespace std;

/*
   <슬라이딩 윈도우>
   1. l은 윈도우의 사이즈, 윈도우 안의 최소값 찾기
   2. dq에 집어넣을때 자기보다 큰수는 모두 삭제 -> 남아있는 수는 오름차순으로 정렬됨 
*/

int main(void)
{
	int n, l;
	cin >> n >> l;
	int ar[n];
	for(int i=0; i<n; ++i)
		cin >> ar[i];

	deque<pair<int,int>> q;
	q.push_back({0,ar[0]});
	printf("%d ", q.front().second);

	for(int i=1; i<n; ++i)
	{
		if(q.front().first == i-l)
			q.pop_front();
					
		while(q.size() && q.back().second >= ar[i])
			q.pop_back();

		q.push_back({i,ar[i]});
		printf("%d ", q.front().second);
	}

	printf("\n");
	return 0;	
}
