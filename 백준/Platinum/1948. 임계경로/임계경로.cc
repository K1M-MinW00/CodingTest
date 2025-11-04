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
vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> rv;
vector<int> inDegree;
vector<int> answer;

void topology(int start, int end)
{
	answer.resize(n + 1);

	queue<int> q;
	q.push(start);

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (pair<int, int> next : v[cur])
		{
			inDegree[next.first]--;
			answer[next.first] = max(answer[next.first], answer[cur] + next.second);
			if (inDegree[next.first] == 0)
				q.push(next.first);
		}
	}


	int cnt = 0;
	vector<bool> visited(n + 1);

	queue<int> rq;
	rq.push(end);

	visited[end] = true;

	while (rq.size())
	{
		int cur = rq.front();
		rq.pop();

		for (pair<int, int> next : rv[cur])
		{
			if (answer[next.first] + next.second == answer[cur])
			{
				cnt++;

				if (visited[next.first])
					continue;

				visited[next.first] = true;
				rq.push(next.first);
			}
		}
	}

	cout << answer[end] << '\n';
	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1);
	rv.resize(n + 1);
	inDegree.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		int a, b, t;
		cin >> a >> b >> t;

		v[a].push_back({ b,t });
		rv[b].push_back({ a,t });
		inDegree[b]++;
	}

	int start, end;
	cin >> start >> end;

	topology(start, end);


	return 0;
}