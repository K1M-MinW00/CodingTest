#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> m;
vector<vector<bool>> v;

int mx[4] ={1,-1,0,0};
int my[4] = {0,0,1,-1};

int sum;
int n,l;

void dfs(int i,int j)
{
    sum += m[i][j];
    
    for(int k=0;k<4;++k)
    {
        int nx = i+mx[k];
        int ny = j+my[k];
        
        if(nx >= 0 && nx < n && ny >=0  && ny < l && v[nx][ny] == false)
        {
            v[nx][ny] = true;
            dfs(nx,ny);
        }
        
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    l = maps[0].length();
    m.resize(n);
    v.resize(n);
    
    
    for(int i=0;i<n;++i)
    {
        m[i].resize(l);
        v[i].resize(l);
        
        for(int j=0;j<l;++j)
        {
            if(maps[i][j] == 'X')
            {
                v[i][j] = true;
                m[i][j] = 0;
            }
               
            else
            {
                v[i][j] = false;
                m[i][j] = maps[i][j] - '0';
            }
                
        }
    }
    
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<l;++j)
        {
            sum = 0;
            if(v[i][j] == false)
            {
                v[i][j] = true;
                dfs(i,j);
            }
            if(sum != 0)
                answer.push_back(sum);
        }
    }
    
    if(answer.size()==0)
        answer.push_back(-1);
    
    else
        sort(answer.begin(),answer.end());
    return answer;
}