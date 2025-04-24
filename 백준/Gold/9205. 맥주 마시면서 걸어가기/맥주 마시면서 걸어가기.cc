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

using namespace std;
#define MAX 101

int n;
pair<int, int> home;
pair<int, int> conv[MAX];
pair<int, int> fest;
bool visited[MAX];

bool solve()
{
	queue<pair<int, int>> q;
	q.push(home);

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		int d = abs(fest.first - cx) + abs(fest.second - cy);

		if (d <= 1000)
			return true;

		for (int i = 0; i < n; ++i)
		{
			if (visited[i])
				continue;

			int conv_d = abs(conv[i].first - cx) + abs(conv[i].second - cy);

			if (conv_d <= 1000)
			{
				visited[i] = true;
				q.push(conv[i]);
			}
		}
	}

	return false;
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
		cin >> home.first >> home.second;

		for (int i = 0; i < n; ++i)
			cin >> conv[i].first >> conv[i].second;

		cin >> fest.first >> fest.second;

		bool answer = solve();

		if (answer)
			cout << "happy\n";
		else
			cout << "sad\n";

		memset(visited, false, sizeof(visited));
	}

	return 0;
}