#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int r = total / num;
    int d = total % num;
    
    if(num % 2 == 1)
    {
        answer.push_back(r);
    
        for(int i=1;i<=num/2;++i)
        {
            answer.push_back(r+i);
            answer.push_back(r-i);
        }
    }
    else
    {
        for(int i=0;i<num/2;++i)
        {
            answer.push_back(r + i + 1);
            answer.push_back(r - i);
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}