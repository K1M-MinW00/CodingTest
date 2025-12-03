#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

stack<int> sts[101];
int solution(int n, int w, int num) {
    int answer = 0;
    
    int size = (n-1) / w + 1;
    int idx = 0;
    
    for(int i=1;i<=n;++i)
    {
        int temp = (i-1) / w;
        
        if(temp % 2 == 0)
            idx = (i-1)%w;
        else
            idx = (w - i%w)%w;
        
        sts[idx].push(i);

    }
    
    for(int i=0;i<w;++i)
    {
        answer = 0;
        while(sts[i].size() > 0)
        {
            int cur = sts[i].top();
            sts[i].pop();
            
            answer++;
            
            if(cur == num)
                return answer;    
        }
        cout << '\n';
    }
    
    return answer;
}