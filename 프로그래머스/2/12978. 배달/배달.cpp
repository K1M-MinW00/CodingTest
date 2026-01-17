#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<pair<int,int>>> v;
vector<int> visited;

void bfs()
{
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = 0;
    
    while(q.size())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for(auto p : v[cur])
        {
            int next = p.first;
            int d = p.second;
            
            if(visited[next] > cnt + d)
            {
                visited[next] = cnt + d;
                q.push({next,cnt+d});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    n = N;
    
    visited.resize(n+1,987654321);
    v.resize(n+1);
    
    for(int i=0;i<road.size();++i)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    bfs();
    
    for(int i=1;i<=n;++i)
    {
        if(visited[i] <= K)
            answer++;
    }
    
    return answer;
}