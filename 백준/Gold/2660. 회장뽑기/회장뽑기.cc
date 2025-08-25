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

int n;
int score[51];
int v[51][51];

void floyd()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				if (v[j][k] > v[j][i] + v[i][k])
					v[j][k] = v[j][i] + v[i][k];
			}
		}
	}
}

void solve()
{
	vector<int> candidate;
	int _score = -1;
	for (int i = 1; i <= n; ++i)
	{
		int d = 0;

		for (int j = 1; j <= n; ++j)
		{
			if (v[i][j] > d)
				d = v[i][j];
		}
		score[i] = d;

		if (_score > d || _score == -1)
			_score = d;
	}

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (score[i] == _score)
		{
			cnt++;
			candidate.push_back(i);
		}
	}

	cout << _score << ' ' << cnt << '\n';

	for (int i : candidate)
		cout << i << ' ';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
				continue;

			v[i][j] = 987654321;
		}
	}

	int a, b;
	while (1)
	{
		cin >> a >> b;

		if (a == -1 && b == -1)
			break;

		v[a][b] = 1;
		v[b][a] = 1;
	}

	floyd();

	solve();
	return 0;
}