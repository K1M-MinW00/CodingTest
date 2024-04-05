#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
vector<vector<int>> v;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };

void dfs(int i, int j)
{
	cnt++;
	v[i][j] = 0;

	for (int k = 0; k < 4; ++k)
	{
		int cx = i + mx[k];
		int cy = j + my[k];

		if (cx < 0 || cy < 0 || cx >= n || cy >= n)
			continue;

		if (v[cx][cy] == 1)
			dfs(cx, cy);
	}
}
int main()
{
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		string line;
		cin >> line;
		v[i].resize(n);
		for (int j = 0; j < n; ++j)
			v[i][j] = (line[j] - '0');
	}

	vector<int> answer;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == 1)
			{
				cnt = 0;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';

	return 0;
}