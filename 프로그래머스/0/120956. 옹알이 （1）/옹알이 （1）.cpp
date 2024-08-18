#include <string>
#include <vector>

using namespace std;

vector<string> can = {"aya","ye","woo","ma"};
vector<bool> used(4,false);

bool func(string str)
{
    bool find = true;
    while(str != "")
    {
        if(str.substr(0,3) == can[0])
            str = str.erase(0,3);
        else if(str.substr(0,2) == can[1])
            str = str.erase(0,2);
        else if(str.substr(0,3) == can[2])
            str = str.erase(0,3);
        else if(str.substr(0,2) == can[3])
            str = str.erase(0,2);
        else
        {
            find = false;
            break;   
        }
    }
    
    return find;
}

int solution(vector<string> babbling) {
    int answer = 0;
        
    for(int i=0;i<babbling.size();++i)
    {
        string str = babbling[i];
        if(func(str))
            answer++;
    }
    return answer;
}