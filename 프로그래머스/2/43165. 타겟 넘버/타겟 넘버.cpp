#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int>& numbers, int& target,int cur, int idx)
{
    if(idx == numbers.size())
    {
        if(cur == target)
            ++answer;
        return;
    }
    
    DFS(numbers,target,cur+numbers[idx],idx+1);
    DFS(numbers,target,cur-numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    
    DFS(numbers,target,0,0);
    
    return answer;
}