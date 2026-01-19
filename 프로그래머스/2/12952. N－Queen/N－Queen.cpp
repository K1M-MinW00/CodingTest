#include <string>
#include <vector>

using namespace std;

int answer = 0;
int v[15];

bool isValid(int depth)
{
    for(int i=0;i<depth;++i)
    {
        if(v[i] == v[depth] || abs(v[depth] - v[i]) == depth - i)
            return false;
    }
    return true;
}

void dfs(int n,int depth)
{
    if(depth == n)
    {
        answer++;
        return;
    }
    
    for(int i=0;i<n;++i)
    {
        v[depth] = i;
        if(isValid(depth))
        {
            dfs(n,depth+1);
        }
    }
}

int solution(int n) {
    dfs(n,0);
    return answer;
}