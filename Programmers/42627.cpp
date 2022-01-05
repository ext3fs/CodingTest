//programmers 디스크 컨트롤러(42627)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
	return a[1] < b[1];
}	

int solution(vector<vector<int>> job)
{
	//작업시간 적은 순으로 정렬
	sort(job.begin(), job.end(), cmp);
    
	int job_cnt = job.size();
	int sec = 0, sum = 0;
Re:	
	while(job.size())
	{
		for(int i=0; i<job.size(); ++i)
		{
			//작업 요청시간이 현재시간보다 작거나 같으면.. 
            		if(job[i][0] <= sec)
			{
             	 	  	sec += job[i][1];
                		sum += sec - job[i][0];
                		job.erase(job.begin()+i);
                		goto Re;
            		}
        	}

   		//{{1,2},{9999999,3}}인 경우
		sec = min_element(job.begin(),job.end())->at(0);
		
	}

	return	sum/job_cnt;
}

int main(void)
{
	vector<vector<int>> vv = {{0, 3}, {1, 9}, {2, 6}};
	int ans = solution(vv);
	cout << ans << endl;
	return 0;
}

