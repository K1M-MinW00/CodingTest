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
#include <tuple>
using namespace std;
#define N 9

int v[N][N];
vector<pair<int, int>> zero;
bool answer = false;

bool check(int x, int y, int value)
{
	for (int i = 0; i < N; ++i)
	{
		if (v[i][y] == value)
			return false;
		if (v[x][i] == value)
			return false;
	}

	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;

	for (int i = sx; i < sx + 3; ++i)
	{
		for (int j = sy; j < sy + 3; ++j)
		{
			if (v[i][j] == value)
				return false;
		}
	}
	return true;
}


void solve(int idx)
{
	if (answer)
		return;

	if (idx == zero.size())
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cout << v[i][j] << ' ';
			}
			cout << '\n';
		}

		answer = true;
		return;
	}

	int cx = zero[idx].first;
	int cy = zero[idx].second;

	for (int i = 1; i <= N; ++i)
	{
		if (check(cx, cy, i))
		{
			v[cx][cy] = i;
			solve(idx + 1);
			v[cx][cy] = 0;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];

			if (v[i][j] == 0)
				zero.push_back({ i,j });
		}
	}

	solve(0);

	return 0;
}