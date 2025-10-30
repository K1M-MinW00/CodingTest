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
#include <sstream>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> color;
vector<bool> visited;

bool answer;

void dfs(int cur)
{
	visited[cur] = true;

	for (int next : v[cur])
	{
		if (visited[next] == false)
		{
			color[next] = (color[cur] + 1) % 2;
			dfs(next);
		}
		else if (color[next] == color[cur])
		{
			answer = false;
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> n >> m;

		v.resize(n + 1);
		color.resize(n + 1);
		visited.resize(n + 1);
		answer = true;

		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (answer)
				dfs(i);
			else
				break;
		}

		if (answer)
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 0; i <= n; ++i)
		{
			v[i].clear();
			visited[i] = false;
			color[i] = 0;
		}
		
	}

	return 0;
}