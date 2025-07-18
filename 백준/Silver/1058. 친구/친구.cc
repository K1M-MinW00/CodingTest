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
#define N 55
#define MAX 987654321

int n, answer = 0;
int v[N][N];

void solve()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
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
			if (line[j] == 'N')
				v[i][j] = MAX;
			else
				v[i][j] = 1;
		}

		if (i == i)
			v[i][i] = 0;
	}

	solve();

	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;

		for (int j = 0; j < n; ++j)
		{
			if (v[i][j] <= 2 && i != j)
				cnt++;
		}

		if (answer < cnt)
			answer = cnt;
	}


	cout << answer;
	return 0;
}