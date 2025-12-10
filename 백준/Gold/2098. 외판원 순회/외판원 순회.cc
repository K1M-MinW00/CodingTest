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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

const int INF = 1e9;

int n;
int v[16][16], dp[16][1 << 16];

int tsp(int here, int visited)
{
	if (visited == (1 << n) - 1) // 모든 정점을 방문했을 때, 현재 위치에서 처음 위치로 돌아갈 수 있는 경로 유무 판단
	{
		return v[here][0] ? v[here][0] : INF;
	}

	int& ret = dp[here][visited];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int i = 0; i < n; ++i)
	{
		if (visited & (1 << i))
			continue;

		if (v[here][i] == 0)
			continue;

		ret = min(ret, tsp(i, visited | (1 << i)) + v[here][i]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << tsp(0, 1) << '\n';
	return 0;
}