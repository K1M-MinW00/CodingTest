#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<int> parent;

bool compare(vector<int> a,vector<int> b)
{
   return a[2] < b[2];    
}

int getParent(int x)
{
    if(parent[x] == x)
        return x;
    
    return parent[x] = getParent(parent[x]);
}

void Union(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool find(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    
    return a == b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    visited.resize(n+1);
    
    sort(costs.begin(),costs.end(),compare);
    
    int max = 0;
    for(auto c : costs)
    {
        if(max < c[1])
            max = c[1];
    }
    
    
    for(int i=0;i<=max;++i)
    {
        parent.push_back(i);
    }
    
    for(auto c : costs)
    {
        if(!find(c[0],c[1]))
        {
            answer += c[2];
            Union(c[0],c[1]);
        }
    }
    
    return answer;
}