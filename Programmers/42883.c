//programmers 42883
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{	
	string answer = "";

	char maxVal = 0;
	int maxIdx = 0;
	int len = number.size();

	for(int i=0; i<len; ++i)
	{
		if(maxVal < number[i])
		{
			maxVal = number[i];
			maxIdx = i;
		}

		if(i == k)
		{
			answer += maxVal;
			i = maxIdx;
			++k;
			maxVal = 0;
		}
	}
	return answer;
}

int	main(void)
{
	string s = "1231234";
	cout << solution(s,3) << endl;
	return	0;
}

