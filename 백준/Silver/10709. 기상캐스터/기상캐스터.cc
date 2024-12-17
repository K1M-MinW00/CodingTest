#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int h, w;
vector<vector<int>> v;

void dfs(int x, int y)
{
	int ny = y + 1;
	int cur = v[x][y];

	if (ny > w)
		return;

	if (v[x][ny] == -1 || v[x][ny] > cur + 1)
	{
		v[x][ny] = cur + 1;
		dfs(x, ny);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w;
	v.resize(h + 1);

	vector<pair<int, int>> q;
	char c;
	string line;

	for (int i = 1; i <= h; ++i)
	{
		v[i].resize(w + 1, -1);
		cin >> line;

		for (int j = 1; j <= w; ++j)
		{
			c = line[j - 1];

			if (c == 'c')
			{
				v[i][j] = 0;
				q.push_back({ i,j });
			}
		}
	}


	for (int i = 0; i < q.size(); ++i)
		dfs(q[i].first, q[i].second);

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}