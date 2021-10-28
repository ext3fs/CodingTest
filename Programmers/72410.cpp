//programmers 72410
#include <string>
#include <iostream>

using namespace std;

string solution(string new_id)
{
	string str = "";
	
	for(char& ch : new_id)
		ch = tolower(ch);

	for(char& ch : new_id)
	{
		if( isalpha(ch) || isdigit(ch) || ch=='-' || ch=='_' || ch=='.' )
			str += ch;	
	}

	for(size_t i=1; i<str.size(); ++i)
	{
		if(str[i-1]=='.' && str[i]=='.')
			str.erase(i--,1);
	}

	if(str.front() == '.')
		str.erase(0,1);

	if(str.back() == '.')
		str.erase(str.size()-1,1);

	if(str.size() == 0)
		str += 'a';
	
	if(str.size() > 15)
		str = str.substr(0, 15);	
	
	if(str.back() == '.')
		str.erase(str.size()-1,1);

	while(str.size() < 3)
		str += str.back();	

	return	str;
}

int	main(void)
{	
	cout << solution("..Z-+..^..") << endl;	
	return	0;
}

