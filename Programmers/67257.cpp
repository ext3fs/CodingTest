//programmers 67257
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void compute(long long& left, long long& right, char op)
{
	if(op == '+')
		left += right;
	else if(op == '-')
		left -= right;
	else
		left *= right;
}

long long solution(string exp)
{
	vector<string> oper = {"+-*","+*-","-+*","-*+","*+-","*-+"}; 
	vector<long long> num;
	vector<char> op;
	long long ans = 0;
	
	for(int i=0; i<exp.size(); ++i){
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'){
			op.push_back(exp[i]);
			exp[i] = ' ';
		}
	}

	stringstream ss(exp);
	long long token;
	while(ss >> token)
		num.push_back(token);	

	for(auto& str : oper)
	{
		vector<long long> tmp_num = num;
		vector<char> tmp_op = op;

		for(char ch : str)
		{
			for(int i=0; i<tmp_op.size(); ++i)
			{
				if(ch != tmp_op[i])
					continue;

				compute(tmp_num[i], tmp_num[i+1], ch);
				tmp_num.erase(tmp_num.begin()+i+1);
				tmp_op.erase(tmp_op.begin()+i);
				--i;
			}
		}
		ans = max(ans, abs(tmp_num[0]));	
	}	
	return ans;
}


int main(void)
{
	string s = "100-200*300-500+20";
	//string s = "50*6-3*2";
	cout << s << endl;
	cout << solution(s) << endl;
	return	0;
}

