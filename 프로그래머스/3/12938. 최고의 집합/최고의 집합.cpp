#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    
    int d = s / n;
    int r = s % n;
    
    answer.assign(n,d);
    
    for(int i=n-1;i>=0;--i)
    {
        if(r > 0)
        {
            r--;
            answer[i]++;
        }
        else
            break;
    }
    return answer;
}