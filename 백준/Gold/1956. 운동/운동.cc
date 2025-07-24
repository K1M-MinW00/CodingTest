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
#define N 405
#define INF 987654321

int v, e;
int graph[N][N];
void floyd_washall()
{
	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			for (int k = 1; k <= v; ++k)
			{
				if (graph[j][i] + graph[i][k] < graph[j][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;

	int a, b, c;

	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			if (i != j)
				graph[i][j] = INF;
		}
	}

	for (int i = 0; i < e; ++i)
	{
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	floyd_washall();

	int answer = INF;

	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			if (i == j)
				continue;

			answer = min(answer, graph[i][j] + graph[j][i]);
		}
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}