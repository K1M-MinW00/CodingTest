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
vector<vector<int>> v;
vector<int> inDegree;
vector<int> times;
vector<int> answer;

void topology()
{
	answer.resize(n + 1);

	queue<int> q;

	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			inDegree[next]--;
			answer[next] = max(answer[next], answer[cur] + times[cur]);
			if (inDegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << answer[i] + times[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n + 1);
	inDegree.resize(n + 1);
	times.resize(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> times[i];

		int num;
		while (true)
		{
			cin >> num;

			if (num == -1)
				break;

			v[num].push_back(i);
			inDegree[i]++;
		}
	}

	topology();

	return 0;
}