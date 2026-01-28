#include <string>
#include <vector>

using namespace std;

long long dp[50001];

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    
    
    if(n % 2 == 1)
        return 0;
    
    for(int i=4;i<=n;i+=2)
    {
        dp[i] = 0;
        
        if(i % 2 == 0)
        {
            long long temp = (dp[i-2] * 3) % 1000000007;
            
            for(int j=4;j<=i;j+=2)
            {
                temp += (dp[i-j] * 2) % 1000000007;
            }
            dp[i] = temp % 1000000007;
        }
    }
    
    
    return dp[n];
}