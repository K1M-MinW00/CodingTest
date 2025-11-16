#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)
    {
        return a.second > b.second;
    }
};


int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    
    sort(jobs.begin(),jobs.end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    
    int time = 0;
    int idx = 0;
    
    while(1)
    {
        if (idx >= jobs.size() && pq.empty())
            break;
        
        while(idx < jobs.size() && jobs[idx][0] <= time)
        {
            pq.push({jobs[idx][0],jobs[idx][1]});
            idx++;
        }
        
        if(pq.size())
        {
            time += pq.top().second;
            answer += (time - pq.top().first);
            pq.pop();
        }
        else
        {
            time = jobs[idx][0];
        }
    }
    
    answer /= jobs.size();

    return answer;
}