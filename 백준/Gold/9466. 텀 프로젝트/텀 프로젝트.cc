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
#define N 100001

int n;
int v[N];
bool visited[N];
bool checked[N];

int cnt = 0;

void solve(int cur)
{
	visited[cur] = true;
	int next = v[cur];

	if (!visited[next])
	{
		solve(next);
	}
	else if (!checked[next])
	{
		for (int i = next; i != cur; i = v[i])
		{
			cnt++;
		}
		cnt++;
	}

	checked[cur] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;

		memset(visited, false, sizeof(visited));
		memset(checked, false, sizeof(checked));

		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}

		cnt = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (visited[i] == false)
			{
				solve(i);
			}
		}

		cout << n - cnt << '\n';

	}
	return 0;
}