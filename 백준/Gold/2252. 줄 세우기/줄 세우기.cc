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
#include <tuple>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> inDegree;

void topology()
{
	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		cout << cur << ' ';

		for (int next : v[cur])
		{
			inDegree[next]--;

			if (inDegree[next] == 0)
				q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1);
	inDegree.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		inDegree[b]++;
	}

	topology();

	return 0;
}