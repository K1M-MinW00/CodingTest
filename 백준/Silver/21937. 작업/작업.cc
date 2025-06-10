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
#define N 100005

int n, m, x, answer = -1;
vector<int> v[N];
bool visited[N];

void solve(int cur)
{
	visited[cur] = true;
	answer++;

	for (int next : v[cur])
	{
		if (visited[next])
			continue;

		solve(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[b].push_back(a);
	}

	cin >> x;

	solve(x);

	cout << answer;

	return 0;
}