#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;

	int v[5][5];

	cin >> n >> m;

	string line;
	for (int i = 0; i < n; ++i)
	{
		cin >> line;

		for (int j = 0; j < m; ++j)
			v[i][j] = line[j] - '0';
	}

	int answer = 0;
	for (int s = 0; s < (1 << (n * m)); ++s) // 1 부터 2^(n*m) 까지 비트마스킹
	{
		int sum = 0;

		for (int i = 0; i < n; ++i) // 가로 더하기
		{
			int cur = 0;

			for (int j = 0; j < m; ++j)
			{
				int k = i * m + j;

				if ((s & (1 << k)) == 0)
					cur = cur * 10 + v[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int j = 0; j < m; ++j) // 세로 더하기
		{
			int cur = 0;

			for (int i = 0; i < n; ++i)
			{
				int k = i * m + j;

				if ((s & (1 << k)) != 0)
					cur = cur * 10 + v[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		answer = max(answer, sum);
	}

	cout << answer;
	return 0;
}