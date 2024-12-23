#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <climits>
using namespace std;

int n, m, answer = INT_MAX;
int a[51][51];
vector<vector<int>> alive;
vector<pair<int, int>> h, c;

void combi(int start, vector<int> temp)
{
	if (temp.size() == m)
	{
		alive.push_back(temp);
		return;
	}

	for (int i = start + 1; i < c.size(); ++i)
	{
		temp.push_back(i);
		combi(i, temp);
		temp.pop_back();
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) h.push_back({ i,j });
			else if (a[i][j] == 2) c.push_back({ i,j });
		}
	}

	vector<int> temp;
	combi(-1, temp);

	for (vector<int> v : alive)
	{
		int ans = 0;

		for (pair<int, int> home : h)
		{
			int minValue = INT_MAX;
			for (int ch : v)
			{
				int dist = abs(home.first - c[ch].first) + abs(home.second - c[ch].second);
				minValue = min(minValue, dist);
			}
			ans += minValue;
		}
		answer = min(answer, ans);
	}
	cout << answer;
	return 0;
}