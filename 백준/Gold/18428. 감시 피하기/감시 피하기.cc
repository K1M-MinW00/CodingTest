#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n;
char v[7][7];
vector<pair<int, int>> teachers, nones;
bool answer;

int mx[] = { 1,0,-1,0 };
int my[] = { 0,1,0,-1 };

bool check(pair<int, int> t)
{
	for (int i = 0; i < 4; ++i)
	{
		int r = t.first, c = t.second;

		while (r >= 0 && c >= 0 && r < n && c < n)
		{
			r += mx[i];
			c += my[i];

			if (v[r][c] == 'O')
				break;
			else if (v[r][c] == 'S')
				return false;
		}
	}

	return true;
}

void solve(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (pair<int, int> t : teachers)
		{
			if (!check(t))
				return;
		}

		answer = true;
		return;
	}

	if (answer)
		return;

	for (int i = idx; i < nones.size(); ++i)
	{
		int r = nones[i].first, c = nones[i].second;

		v[r][c] = 'O';
		solve(i + 1, cnt + 1);
		v[r][c] = 'X';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 'X')
				nones.push_back({ i,j });

			else if (v[i][j] == 'T')
				teachers.push_back({ i,j });
		}
	}

	solve(0, 0);

	if (answer)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}