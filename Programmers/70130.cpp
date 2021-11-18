//programmers 스타수열(70130)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

/*
   ex) 1 2 3 5 2 4 2
   가장 빈도수가 많은 2부터(빈도수가 3이므로 스타수열 사이즈 6이상 될수없음)
   1 2, 5 2, 4 2 가 스타수열 -> 2의 앞뒤 인덱스가 사용가능한지 판단하면 됨 

   ex) 1 1 1 1 1 2 3 2
   가장 빈도수가 많은 1이지만 스타수열 사이즈는 2
   2는 4임 -> 가장 빈도수가 높다고 스타수열 사이즈가 높은건 아님   
*/

int solution(vector<int> a)
{
	for(int i : a)
		cout << i << " ";
	cout << endl;

	vector<int> idx(500000, -1);
	vector<int> cnt(500000);

	for(int i=0; i<a.size(); ++i)
	{
		int val = a[i];
		
		if(i - idx[val] >= 2)
		{
			++cnt[val];
			idx[val] = i;
			cout << "first : " << val << endl;
			cout << "cnt" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(cnt[j])
					cout << j << " : " << cnt[j] << endl;
			cout << "idx" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(idx[j]>=0)
					cout << j << " : " << idx[j] << endl;
		}
		else if(i+1 < a.size() && a[i+1] != val)
		{
			++cnt[val];
			idx[val] = i+1;
			cout << "second : " << val << endl;
			cout << "cnt" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(cnt[j])
					cout << j << " : " << cnt[j] << endl;
			cout << "idx" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(idx[j]>=0)
					cout << j << " : " << idx[j] << endl;
		}
		else{
			idx[val] = i;
			cout << "third : " << val << endl;
			cout << "cnt" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(cnt[j])
					cout << j << " : " << cnt[j] << endl;
			cout << "idx" << endl;	
			for(int j=0; j<cnt.size(); ++j)
				if(idx[j]>=0)
					cout << j << " : " << idx[j] << endl;
		}
	}

	cout << "ans" << endl;	
	for(int i=0; i<cnt.size(); ++i)
		if(cnt[i])
			cout << i << " : " << cnt[i] << endl;

	return *max_element(cnt.begin(),cnt.end()) * 2;
}

int main(void)
{
	//vector<int> v = {0,3,3,0,7,2,0,2,2,0};
	//vector<int> v = {5,2,3,3,5,3};
	vector<int> v = {2,5,3,2};
	int ans = solution(v);
	cout << "ans = " << ans << endl;
	return	0;
}
