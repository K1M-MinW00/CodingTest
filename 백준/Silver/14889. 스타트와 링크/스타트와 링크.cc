#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int n, answer = INT_MAX;
int a[20][20];
bool team[20];


void solve(int start, int cnt)
{
	vector<int> team1;
	vector<int> team2;

	int s1 = 0, s2 = 0;

	if (cnt == (n / 2))
	{
		for (int i = 0; i < n; ++i)
		{
			if (team[i] == true)
				team1.push_back(i);
			else
				team2.push_back(i);
		}

		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = 0; j < n / 2; ++j)
			{
				s1 += a[team1[i]][team1[j]];
				s2 += a[team2[i]][team2[j]];
			}
		}

		int value = abs(s1 - s2);

		answer = min(value, answer);
		return;
	}

	for (int i = start; i < n; ++i)
	{
		if (team[i])
			continue;
		else
		{
			team[i] = true;
			solve(i, cnt + 1);
			team[i] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

	solve(0, 0);

	cout << answer;
	return 0;
}