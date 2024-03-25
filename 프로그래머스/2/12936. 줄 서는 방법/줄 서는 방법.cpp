#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;

    vector<long long> f(n+1,1); // 1 ~ n 까지 피보나치 수열
    vector<int> num(n); // 1 ~ n 까지 자연수
    
    for(int i=2;i<=n;++i)
        f[i] = f[i-1] * i;
    
    for(int i=0;i<n;++i)
        num[i] = i+1;
    
    int i = 1; // i번째 줄서는 사람
    
    while(i < n)
    {
        long long tmp = f[n-i]; // n-i 번째 피보나치
        int idx = (k-1)/tmp; // 나눈 몫이 i번째 줄서는 사람의 번호 (앞에서부터)
        answer.push_back(num[idx]);
        num.erase(num.begin()+idx);
        
        ++i;
        k %= tmp;
        
        if(k == 0)
            k = tmp;
    }
    
    answer.push_back(num[0]);
    return answer;
}