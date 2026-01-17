#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0;i<numbers.size();++i)
    {
        long long n = numbers[i];
        
        if(n % 2 == 0)
            answer.push_back(n+1);
        
        else
        {
            long long temp = (n+1) & (-n);
            long long result = (n | temp) &  (~(temp >> 1));
            answer.push_back(result);
        }
    }
    return answer;
}