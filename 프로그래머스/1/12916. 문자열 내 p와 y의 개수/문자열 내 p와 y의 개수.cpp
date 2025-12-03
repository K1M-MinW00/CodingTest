#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int _p = 0, _y = 0;
    
    for(int i=0;i<s.length();++i)
    {
        if(s[i] == 'p' || s[i] == 'P')
            _p++;
        else if(s[i] == 'y' || s[i] == 'Y')
            _y++;
    }
    
    if(_p == _y)
        return true;
    else 
        return false;
}