//programmers 67256
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	int pos_left=10, pos_right=12;
	char ch;

	if(hand == "left")
		ch = 'L';
	else
		ch = 'R';
	
	int i=0;
	for(int num : numbers)
	{
		++i;

		cout << i << pos_left << pos_right << endl;
		if(num == 0)
			num = 11;

		if(num%3 == 1)
		{
			answer.push_back('L');
			pos_left = num;
			continue;
		}

		if(num%3 == 0)
		{
			answer.push_back('R');
			pos_right = num;
			continue;
		}

		int dist_left=0,dist_right=0;
		int tmp_left = pos_left;
		int tmp_right = pos_right;

		//left
		if(pos_left%3 == 1)
		{
			++tmp_left;
			++dist_left;
		}	
		dist_left += abs(num-tmp_left)/3;

		//right
		if(pos_right%3 == 0)
		{
			--tmp_right;
			++dist_right;
		}	
		dist_right += abs(num-tmp_right)/3;


		if(dist_left == dist_right)
			answer.push_back(ch);
		else
			answer.push_back(dist_left-dist_right>0 ? 'R':'L');

		if(answer.back() == 'L')
			pos_left = num;
		else
			pos_right = num;

		cout << i << dist_left << dist_right << endl;
		cout << i << pos_left << pos_right << endl;
	}

	return answer;
}

int	main(void)
{
	//vector<int>	numbers = {1,3,4,5,8,2,1,4,5,9,5};
	vector<int>	numbers = {7,0,8,2,8,3,1,5,7,6,2};
	//vector<int>	numbers = {1,2,3,4,5,6,7,8,9,0};

	//cout << solution(numbers, "right") << endl;	
	cout << solution(numbers, "left") << endl;	
	return	0;
}

