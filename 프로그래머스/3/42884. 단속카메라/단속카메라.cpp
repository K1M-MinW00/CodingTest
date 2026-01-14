#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    
    int cam = routes[0][1];
    int n = routes.size();
    
    for(int i=1;i<n;++i)
    {
        if(routes[i][1] < cam)
            cam = routes[i][1];
        else if(routes[i][0] > cam)
        {
            answer++;
            cam = routes[i][1];
        }
    }
    return answer;
}