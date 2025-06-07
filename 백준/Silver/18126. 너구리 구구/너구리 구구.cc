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
#define N 5001

int n;
long long answer = 0;

bool visited[N];
int v[N][N];
vector<int> graph[N];

void solve(int cur, long long sum)
{
	if (sum > answer)
		answer = sum;

	visited[cur] = true;

	for (int next : graph[cur])
	{
		if (visited[next])
			continue;

		visited[next] = true;
		solve(next, sum + v[cur][next]);
		visited[next] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;

	cin >> n;


	for (int i = 0; i < n - 1; ++i)
	{
		cin >> a >> b >> c;
		v[a][b] = c;
		v[b][a] = c;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	solve(1, 0);

	cout << answer;

	return 0;
}