#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;
#define N 501

int n, m;
int inDegree[N];
bool graph[N][N];

void topology_sort()
{
	queue<int> q;

	for (int cur = 1; cur <= n; ++cur)
	{
		if (inDegree[cur] == 0)
			q.push(cur);
	}

	vector<int> answer;
	bool unCertain = false;
	bool isImpossible = false;

	for (int i = 0; i < n; ++i)
	{
		if (q.empty())
		{
			isImpossible = true;
			break;
		}

		if (q.size() >= 2)
		{
			unCertain = true;
			break;
		}

		int cur = q.front();
		q.pop();

		answer.push_back(cur);

		for (int next = 1; next <= n; ++next)
		{
			if (graph[cur][next] == 1)
			{
				if (--inDegree[next] == 0)
					q.push(next);
			}
		}
	}

	if (unCertain)
	{
		cout << "?\n";
	}
	else if (isImpossible)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		for (int i : answer)
			cout << i << ' ';
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;

		vector<int>order(n);

		memset(inDegree, 0, sizeof(inDegree));
		memset(graph, 0, sizeof(graph));

		for (int i = 0; i < n; ++i)
		{
			cin >> order[i];
		}

		for (int i = 0; i < order.size(); ++i)
		{
			int s = order[i];
			for (int j = i + 1; j < order.size(); ++j)
			{
				int e = order[j];
				graph[s][e] = 1;
				inDegree[e]++;
			}
		}

		cin >> m;

		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;

			if (graph[a][b] == 1)
			{
				graph[a][b] = 0;
				graph[b][a] = 1;
				inDegree[b]--;
				inDegree[a]++;
			}
			else
			{
				graph[b][a] = 0;
				inDegree[a]--;
				graph[a][b] = 1;
				inDegree[b]++;
			}
		}

		topology_sort();
	}

	return 0;
}