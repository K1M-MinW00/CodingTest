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
int a, b, n, m, s, e;
int visited[1001];
vector<int> v[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}


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

		for (int e : v[cur])
		{
			if (e > n)
				continue;

			if (visited[e] == 0 || visited[e] > cnt + 1)
			{
				visited[e] = cnt + 1;
				q.push({ e,cnt + 1 });
			}
		}
	}

	cout << answer << '\n';
	return 0;
}