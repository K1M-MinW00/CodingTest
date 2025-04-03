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

using namespace std;

int s;
string n;

char v[1001][1001];

void print__(int r, int c)
{
	for (int i = c + 1; i <= c + s; ++i)
		v[r][i] = '-';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s >> n;

	int r = s * 2 + 3;
	int c = s + 2;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < (c + 1) * n.length(); ++j)
			v[i][j] = ' ';

	int idx = 0;

	for (int t = 0; t < n.length(); ++t)
	{
		int num = n[t] - '0';

		for (int i = 0; i < r; ++i)
		{
			if (i == 0) // 맨 윗줄 -
			{
				if (num != 1 && num != 4)
					print__(i, idx);
			}
			else if (i == s + 1) // 가운데 줄 -
			{
				if (num != 1 && num != 7 && num != 0)
					print__(i, idx);
			}
			else if (i == r - 1) // 맨 아래 줄 -
			{
				if (num != 1 && num != 4 && num != 7)
					print__(i, idx);
			}
			else if (i <= s) // 위쪽 |
			{
				if (num == 4 || num == 5 || num == 6 || num == 8 || num == 9 || num == 0) // 왼쪽 |
					v[i][idx] = '|';

				if (num <= 4 || num >= 7) // 오른쪽 |
					v[i][idx + c - 1] = '|';
			}
			else // 아래쪽 |
			{
				if (num == 2 || num == 6 || num == 8 || num == 0) // 왼쪽 |
					v[i][idx] = '|';
				if (num != 2)
					v[i][idx + c - 1] = '|';
			}
		}

		idx += c + 1;
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < (c + 1) * n.length(); ++j)
			cout << v[i][j];
		cout << '\n';
	}

	return 0;
}