#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<char>> v;
string answer;

void solve(int r, int c, int size)
{
	bool same = true;
	char color = v[r][c];
	for (int i = r; i < r + size; ++i)
	{
		if (!same)
			break;
		for (int j = c; j < c + size; ++j)
		{
			if (v[r][c] != v[i][j])
			{
				same = false;
				break;
			}
		}
	}

	if (same || size == 1)
	{
		answer += color;
		return;
	}
	else
	{
		answer += "(";
		solve(r, c, size / 2);
		solve(r, c + size / 2, size / 2);
		solve(r + size / 2, c, size / 2);
		solve(r + size / 2, c + size / 2, size / 2);
		answer += ")";
		return;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		v[i].resize(n);

	for (int i = 0; i < n; ++i)
	{
		string line;
		cin >> line;

		for (int j = 0; j < n; ++j)
			v[i][j] = line[j];
	}

	solve(0, 0, n);

	cout << answer;
	return 0;
}