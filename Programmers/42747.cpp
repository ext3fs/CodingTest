//programmers H-Index (42747)
#include <iostream>
#include <vector>
using namespace std;

//H-Index = min(몇편?,몇번?)
int solution(vector<int> v)
{
    int ans = 0;
    int start = 0;
    int end = v.size();
    
    while(start <= end)
    {
        int h = (start + end)/2;
        
        int cnt = 0;
        for(int val : v)
            if(h <= val)
                ++cnt;
        
        if(cnt >= h)
            start = h + 1;
        else
            end = h - 1;
    }
    
    return end;
}
