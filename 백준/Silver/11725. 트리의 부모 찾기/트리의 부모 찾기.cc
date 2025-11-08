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

using namespace std;

int n;
vector<vector<int>> v;
vector<bool> visited;
vector<int> answer;

void dfs(int cur)
{
	visited[cur] = true;

	for (int next : v[cur])
	{
		if (visited[next])
			continue;

		answer[next] = cur;
		dfs(next);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 1);
	visited.resize(n + 1);
	answer.resize(n + 1);

	for (int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; ++i)
		cout << answer[i] << "\n";

	return 0;
}