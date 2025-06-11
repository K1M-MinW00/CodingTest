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
#include <bitset>

using namespace std;
int a, b, n;
int visited[10005];
int v[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	cin >> a >> b;

	queue<pair<int, int>> q;
	q.push({ a,0 });
	visited[a] = 0;

	int answer = -1;

	while (q.size())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == b)
		{
			answer = cnt;
			break;
		}

		int jump = v[cur];

		for (int next = cur + jump; next <= n; next += jump)
		{
			if (visited[next] == 0 || visited[next] > cnt + 1)
			{
				visited[next] = cnt + 1;
				q.push({ next , cnt + 1 });
			}
		}

		for (int prev = cur - jump; prev >= 1; prev -= jump)
		{
			if (visited[prev] == 0 || visited[prev] > cnt + 1)
			{
				visited[prev] = cnt + 1;
				q.push({ prev , cnt + 1 });
			}
		}
	}

	cout << answer << '\n';
	return 0;
}