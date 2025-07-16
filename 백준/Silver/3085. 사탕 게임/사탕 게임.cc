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
#define N 51

int n;
char v[N][N];
int answer = 0;

void check()
{
	for (int i = 0; i < n; ++i)
	{
		int temp = 1;
		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] == v[i][j + 1])
				temp++;
			else
			{
				if (temp > answer)
					answer = temp;
				temp = 1;
			}
		}
	}

	for (int j = 0; j < n; ++j)
	{
		int temp = 1;
		for (int i = 0; i < n; ++i)
		{
			if (v[i][j] == v[i + 1][j])
				temp++;
			else
			{
				if (temp > answer)
					answer = temp;
				temp = 1;
			}
		}
	}

}

void solve()
{

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			swap(v[i][j], v[i][j + 1]);
			check();
			swap(v[i][j], v[i][j + 1]);
		}
	}

	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			swap(v[i][j], v[i + 1][j]);
			check();
			swap(v[i][j], v[i + 1][j]);
		}
	}

	cout << answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	string line;

	for (int i = 0; i < n; ++i)
	{
		cin >> line;

		for (int j = 0; j < n; ++j)
		{
			v[i][j] = line[j];
		}
	}

	solve();

	return 0;
}