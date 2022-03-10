//programmers 67256
#include <iostream>
#include <vector>
using namespace std;

string solution(vector<int> num, string hand)
{
    string ans = "";
    int left=10, right=12; 
    int distL, distR;
        
    for(int val : num)
    {
        if(val == 0)
            val = 11;
        
        if(val%3 == 1)
    		ans.push_back('L'), left=val;
        else if(val%3 == 0)
    		ans.push_back('R'), right=val;
        else
	{
    	    if(left%3 == 2)        
            	distL = abs(left-val)/3;
            else
            	distL = abs(left+1-val)/3 + 1;
    		
            if(right%3 == 2)        
            	distR = abs(right-val)/3;
            else
            	distR = abs(right-1-val)/3 + 1;
            
            if(distL < distR)
    			ans.push_back('L'), left=val;
            else if(distL > distR)
    			ans.push_back('R'), right=val;
            else{
        		if(hand == "left")        
    				ans.push_back('L'), left=val;
                	else
    				ans.push_back('R'), right=val;
            }
        }
    }
    return ans;
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

