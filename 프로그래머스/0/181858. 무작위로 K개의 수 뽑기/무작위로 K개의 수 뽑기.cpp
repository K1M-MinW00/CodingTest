#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    bool num[100001]={false,};
    
    for(int i=0;i<arr.size();++i)
    {
        int n = arr[i];
        
        if(num[n] == false)
        {
            answer.push_back(n);
            num[n] = true;
        }
        
        if(answer.size() == k)
            break;
    }
    
    if(answer.size() == k)
        return answer;
    
    while(answer.size() != k)
        answer.push_back(-1);
    
    return answer;
}