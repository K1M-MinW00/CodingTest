#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
queue<pair<int, int>> q;

int mx[4] = { 1,-1,0,0 };
int my[4] = { 0,0,1,-1 };

int bfs(vector<vector<int>>& vv)
{
	int virus = 0;
	queue<pair<int, int>> qq = q;
	vector<vector<int>> v = vv;
	while (qq.size())
	{
		int cx = qq.front().first;
		int cy = qq.front().second;
		qq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (v[nx][ny] == 0)
			{
				v[nx][ny] = 2;
				virus++;
				qq.push({ nx,ny });

			}
		}
	}

	return virus;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vector<vector<int>> v;
	v.resize(n);
	int cnt1 = 0, cnt0 = 0;

	vector<pair<int, int>> zero;
	for (int i = 0; i < n; ++i)
	{
		v[i].resize(m);

		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
				q.push({ i,j });

			else if (v[i][j] == 0)
			{
				zero.push_back({ i,j });
				cnt0++;
			}
			else
				cnt1++;
		}
	}

	int answer = 0;
	cnt1 += 3;

	for (int i = 0; i < zero.size() - 2; ++i)
	{
		v[zero[i].first][zero[i].second] = 1;

		for (int j = i + 1; j < zero.size() - 1; ++j)
		{
			v[zero[j].first][zero[j].second] = 1;

			for (int k = j + 1; k < zero.size(); ++k)
			{
				v[zero[k].first][zero[k].second] = 1;

				int cnt2 = bfs(v) + q.size();
				int temp = n * m - cnt2 - cnt1;
				answer = max(answer, temp);
				v[zero[k].first][zero[k].second] = 0;
			}

			v[zero[j].first][zero[j].second] = 0;
		}
		v[zero[i].first][zero[i].second] = 0;
	}

	cout << answer;
	return 0;
}