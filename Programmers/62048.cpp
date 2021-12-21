//programmers 멀쩡한사각형(62048)
#include <iostream>
using namespace std;

/*
   브렌젠험 알고리즘 참고
   1, 남은 사각형의 수는 대각선을 중심으로 대칭
   2, w를 하나씩 키우면서 남는 사각형의 갯수 더해줌

   cf) gcd() 패턴을 이용할경우
	제외되는 사각형 -> 타일(0,0)에서 타일(w/gcd, h/gcd)로 갈때 밟게 되는 타일의 수    
*/

long long solution(int w, int h)
{
	long long ans = 0;

	for(int i=0; i<w; ++i)
	{
		ans += (long long)h*i/w;

		cout << i+1 << " : " << h*i/w << endl;
	}

	return ans*2;	
}

int main(void)
{
	long long ans = solution(8,12);
	cout << ans << endl;	
	return	0;
}
