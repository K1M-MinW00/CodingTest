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

using namespace std;
#define INF 987654321

int n, answer = INF;
int a[11];
int visited[11], comp[11];
vector<int> v[11];

pair<int, int> dfs(int idx, int value)
{
	visited[idx] = 1;
	
	pair<int, int> ret = { 1,a[idx] }; // 사이즈 - 인구수

	for (int next : v[idx])
	{
		if (comp[next] != value) // 색이 다르면 패스
			continue;

		if (visited[next]) // 이미 방문했으면 패스
			continue;

		pair<int, int> tmp = dfs(next, value);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];


	int m, tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}


	for (int i = 1; i < (1 << n) - 1; i++)
	{
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);

		int idx1 = -1, idx2 = -1;

		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
				idx2 = j + 1;
		}

		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);

		if (comp1.first + comp2.first == n) // 합쳐서 모든 노드를 방문했을 때, 최소값
			answer = min(answer, abs(comp1.second - comp2.second));
	}

	if (answer == INF)
		cout << -1;
	else
		cout << answer;


	return 0;
}