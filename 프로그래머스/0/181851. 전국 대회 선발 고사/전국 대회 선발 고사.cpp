#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<pair<int,int>> temp; // idx - rank
    
    for(int i=0;i<rank.size();++i)
    {
        if(attendance[i])
            temp.push_back(make_pair(rank[i],i));       
    }
    
    sort(temp.begin(),temp.end());
    
    answer = 10000 * (temp[0].second);
    answer += 100 * (temp[1].second);
    answer += (temp[2].second);
    
    return answer;
}