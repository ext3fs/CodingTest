//programmers 조이스틱(42860)
#include <iostream>
using namespace std;

/*
   ex) BAAABAB 
   1, A로만 이루어진 문자열을 찾아낸다
   2, AAA 문자열의 left idx, right index를 찾는다
   3, l + (len-r) + min(l,(len-r)))가 해당 AAA을 제외시킨 최소이동
   4, 모든 AAA형태의 문자열에 대해서 다 구해본다
*/

int solution(string s)
{
	//알파벳 변환횟수는 따로 구한다
	int change = 0;
	for(char c : s)
		change += min(c - 'A', 'Z' - c + 1);

	int len = s.size();	
	int move = len - 1;
	// 첫글자에 커서가 있으므로, 첫글자가 A든 아니든 최소 move는 똑같다.
	// 첫글자는 A가 아니라고 생각하는게 편하다.	
	for(int i=1; i<len; ++i)
	{
		if(s[i] != 'A')
			continue;

		int l = i-1;
		int r = i+1;
		for(; r<len; ++r)
			if(s[r] != 'A')
				break;

		move = min(move, l + (len-r) + min(l,(len-r)));
		i = r;		
	}
	
	return change + move;	
}

int main(void)
{
	string s = "JAN";
	int ans = solution(s);
	cout << "ans = " << ans << endl;	
	return	0;
}
