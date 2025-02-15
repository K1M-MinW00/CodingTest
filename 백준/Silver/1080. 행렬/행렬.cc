#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int n, m, answer = 0;
int a[51][51];
int b[51][51];

void solve()
{
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = 0; j < m - 2; ++j)
		{
			if (a[i][j] != b[i][j])
			{
				for (int x = i; x < i + 3; ++x)
				{
					for (int y = j; y < j + 3; ++y)
						a[x][y] = 1 - a[x][y];
				}
				answer++;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] != b[i][j])
			{
				cout << -1;
				return;
			}
		}
	}
	cout << answer;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	string line;

	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			a[i][j] = line[j] - '0';
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			b[i][j] = line[j] - '0';
	}

	solve();
	return 0;
}