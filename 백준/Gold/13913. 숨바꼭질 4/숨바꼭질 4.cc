#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> visited(200005);
vector<int> seq(200005);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	visited[n] = 1;
	queue<int> q;
	q.push(n);

	int size = 0;
	while (q.size())
	{
		int cur = q.front();
		q.pop();

		if (cur == m)
		{
			size = visited[cur];
			break;
		}

		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (next >= 200005 || next < 0 || visited[next])
				continue;
			visited[next] = visited[cur] + 1;
			seq[next] = cur;
			q.push(next);
		}
	}

	vector<int> answer;

	for (int i = m; i != n; i = seq[i])
		answer.push_back(i);

	answer.push_back(n);

	reverse(answer.begin(), answer.end());

	cout << size - 1 << '\n';
	for (auto e : answer)
		cout << e << ' ';
	return 0;
}
