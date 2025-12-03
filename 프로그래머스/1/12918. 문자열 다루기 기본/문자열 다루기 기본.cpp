#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;
    
    if(s.length() == 4 || s.length() == 6)
    {
        for(int i=0;i<s.length();++i)
        {
            if('0' > s[i] || s[i] > '9')
                return false;
        }
        answer = true;
    }
    
    return answer;
}