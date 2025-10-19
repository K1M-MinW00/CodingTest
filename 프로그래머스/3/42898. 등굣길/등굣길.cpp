#include <string>
#include <vector>
#include <queue>
using namespace std;

#define N 101
#define M 1000000007

int dp[N][N];

int solution(int m, int n, vector<vector<int>> puddles)
{
	int answer = 0;

	for (int i = 0; i < puddles.size(); ++i)
		dp[puddles[i][1]][puddles[i][0]] = -1;
	
	dp[1][1] = 1;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (dp[i][j] == -1)
				continue;

			int a = dp[i - 1][j] != -1 ? dp[i - 1][j] : 0;
			int b = dp[i][j - 1] != -1 ? dp[i][j - 1] : 0;

			dp[i][j] += (a + b) % M;
		}
	}

	answer = dp[n][m];
	return answer;
}