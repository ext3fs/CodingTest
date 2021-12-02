#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
	string str;
	getline(cin,str);

	int cnt = 0;
	stringstream ss(str);
	while(getline(ss, str, ' '))
		if(str.size())
			++cnt;

	cout << cnt << endl;	
	return 0;
}
