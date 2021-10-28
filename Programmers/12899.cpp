//programmers 12899
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
	string answer = "";
	vector<string> v;
	int val;

	do{
	   	val = n%3;
		n = n/3;
		if(val == 0){
			v.push_back("4");
			n -= 1;
		}
		else
			v.push_back(to_string(val));
		
	}while(n > 0);

	for(auto itr=v.rbegin(); itr!=v.rend(); ++itr)
		answer.append(*itr);

	return	answer;
}

int	main(void)
{
	for(int i=1; i<21; ++i)
		cout << solution(i) << endl;
	return 0;
}

