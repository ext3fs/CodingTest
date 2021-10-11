//programmers 43163
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(string& a, string& b)
{
	int cnt = 0;
	for(size_t i=0; i<a.size(); ++i)
		if(a[i] != b[i])
			++cnt;
	if(cnt < 2)
		return true;
	return false;	
}

int bfs(string& begin, string& target, vector<string>& words)
{
	queue<pair<string,int>> q;
	vector<bool> visit(words.size());
	q.push(make_pair(begin,0));

	while(!q.empty())
	{
		auto node = q.front();
		q.pop();

		if(node.first == target)
			return node.second;

		for(size_t i=0; i<words.size(); ++i)
		{
			if(visit[i])
				continue;

			if(isPossible(node.first, words[i])){
				visit[i] = true;
				q.push(make_pair(words[i], node.second+1));
			}	
		}
	}
	return 0;
}

int solution(string begin, string target, vector<string> words)
{
	return bfs(begin, target, words);
}

int main(void)
{
	vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
	int ans = solution("hit","cog",v);
	cout << "ans = " << ans << endl;
	return	0;
}


