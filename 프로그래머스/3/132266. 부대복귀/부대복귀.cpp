#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> answer;
vector<bool> visited;
int d;

void dfs(int start)
{
    fill(visited.begin(),visited.end(),false);
    
    queue<pair<int,int>> q;
    q.push({start,0});
    visited[start] = true;
    
    while(q.size())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cur == d)
        {
            answer.push_back(cnt);
            return;
        }
        
        for(int next : v[cur])
        {
            if(visited[next])
                continue;
            
            visited[next] = true;
            q.push({next,cnt+1});
        }
    }
    answer.push_back(-1);
    return;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    v.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<roads.size();++i)
    {
        int start = roads[i][0];
        int dest = roads[i][1];
        
        v[start].push_back(dest);
        v[dest].push_back(start);
    }
    
    d = destination;
    
    for(int s : sources)
    {
        dfs(s);
    }
    
    return answer;
}