#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;

bool visited[10001];
bool visitAll;

void dfs(string start, int cnt)
{
    answer.push_back(start);
    
    if(cnt == ticket.size())
    {
        visitAll = true;
    }
    
    for(int i=0;i< ticket.size();++i)
    {
        if(visited[i])
            continue;
        
        if(ticket[i][0] == start)
        {
            visited[i] = true;
            dfs(ticket[i][1],cnt+1);
            
            if(!visitAll)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(),tickets.end());
    ticket = tickets;
    
    dfs("ICN", 0 );
    
    return answer;
}