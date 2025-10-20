#include <string>
#include <vector>

using namespace std;

#define M 1000000007
#define N 100001

int dp[N];

int solution(int n, vector<int> money)
{
	int answer = 0;
	dp[0] = 1;

	for (int i = 0; i < money.size(); i++)
	{
		for (int j = money[i]; j <= n; ++j)
		{
			dp[j] += dp[j - money[i]];
			dp[j] %= M;
		}
	}

	answer = dp[n];
	return answer;
}
