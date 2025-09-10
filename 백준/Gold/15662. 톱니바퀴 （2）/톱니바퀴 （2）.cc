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

int n, k, a, b;
string s[1001];

void rot(int start, bool cw)
{
	if (cw) // 시계 , 오른쪽으로 회전
	{
		rotate(s[start].begin(), s[start].end() - 1, s[start].end());
	}
	else // 반시계 , 왼쪽으로 회전
	{
		rotate(s[start].begin(), s[start].begin() + 1, s[start].end());
	}
}

int rotate_l(int start)
{
	for (int i = start; i >= 2; i--)
	{
		if (s[i][6] == s[i - 1][2])
			return i;
	}
	return 1;
}

int rotate_r(int start)
{
	for (int i = start; i <= n - 1; i++)
	{
		if (s[i][2] == s[i + 1][6])
			return i;
	}
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b;

		int left = rotate_l(a);
		int right = rotate_r(a);


		bool dir = (b == 1);
		for (int j = a; j >= left; j--)
		{
			rot(j, dir);
			dir = !dir;
		}

		dir = (b != 1);
		for (int j = a + 1; j <= right; j++)
		{
			rot(j, dir);
			dir = !dir;
		}
	}

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (s[i][0] == '1')
			answer++;
	}

	cout << answer << '\n';
	return 0;
}