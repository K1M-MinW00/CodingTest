#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<char>> v;
pair<int,int> start,lever;
vector<vector<int>> visited;

int mx[] = {1,-1,0,0};
int my[] = {0,0,1,-1};

int bfs()
{
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    
    while(q.size())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        int cnt = visited[cx][cy];
        q.pop();
        
        for(int i=0;i<4;++i)
        {
            int nx = cx + mx[i];
            int ny = cy + my[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if(v[nx][ny] == 'X')
                continue;
            
            if(visited[nx][ny] > cnt + 1)
            {
                q.push({nx,ny});
                visited[nx][ny] = cnt + 1;
            }
            
            if(v[nx][ny] == 'L')
            {
                return cnt+1;
            }
        }
    }
    
    return -1;
}

int bfs_(int l)
{
    queue<pair<int,int>> q;
    q.push(lever);
    
    for(int i=0;i<n;++i)
        fill(visited[i].begin(),visited[i].end(),987654321);
    visited[lever.first][lever.second] = l;
    
    while(q.size())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        int cnt = visited[cx][cy];
        q.pop();
        
        for(int i=0;i<4;++i)
        {
            int nx = cx + mx[i];
            int ny = cy + my[i];
            
            if(nx < 0 || ny < 0 || nx>=n || ny>=m)
                continue;
            
            if(v[nx][ny] == 'X')
                continue;
            
            if(visited[nx][ny] > cnt + 1)
            {
                q.push({nx,ny});
                visited[nx][ny] = cnt + 1;
            }
            
            if(v[nx][ny] == 'E')
            {
                cout << cnt + 1;
                return cnt + 1;
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    n = maps.size();
    m = maps[0].length();
    v.resize(n);
    visited.resize(n);
    
    for(int i=0;i<maps.size();++i)
    {
        v[i].resize(m);
        visited[i].resize(m,987654321);
        
        for(int j=0;j<m;++j)
        {
            if(maps[i][j] == 'S')
                start = {i,j};
            
            else if(maps[i][j] == 'L')
                lever = {i,j};
            
            v[i][j] = maps[i][j];
        }
    }
    
    int l = bfs();
    
    if(l == -1)
        return -1;
    
    answer = bfs_(l);
    
    return answer;
}