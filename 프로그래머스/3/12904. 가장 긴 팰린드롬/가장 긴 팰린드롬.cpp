#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int n = s.length();
    
    for(int i=0;i<n;++i)
    {
        
        int odd_l = 1;
        for(int j=1;i+j<n && i-j>=0;++j)
        {
            if(s[i+j] == s[i-j])
                odd_l += 2;
            else
                break;
        }
        answer = max(answer,odd_l);
        
        int even_l = 0;
        for(int j=0;i+j+1<n && i-j>=0;++j)
        {
            if(s[i+j+1] == s[i-j])
                even_l +=2;
            else
                break;
        }
        
        answer = max(answer,even_l);
    }

    return answer;
}