#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    
    for(int j : works)
        pq.push(j);
    
    while(n > 0 && pq.size() > 0)
    {
        int first = pq.top();
        pq.pop();
        
        if(pq.empty())
        {
            first -= min(first,n);
            n -= min(first,n);
        }
        else
        {
            first--;
            n--;
        }
        
        if(first > 0)
            pq.push(first);
    }
    
    
    while(pq.size() > 0)
    {
        long long first = pq.top();
        pq.pop();
        answer += first * first; 
    }
    
    return answer;
}