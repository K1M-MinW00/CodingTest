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

using namespace std;
#define N 11

int n, m;
vector<long long> v(N);

int answer = 987654321;
int maxCnt = 0;

int count(long long bits)
{
	int cnt = 0;

	while (bits)
	{
		cnt += bits & 1;
		bits >>= 1;
	}

	return cnt;
}

void solve(int idx, long long bits, int cnt)
{
	int music = count(bits);

	if (music > maxCnt)
	{
		maxCnt = music;
		answer = cnt;
	}
	else if (music == maxCnt)
		answer = min(answer, cnt);

	if (idx == n)
		return;

	solve(idx + 1, bits | v[idx], cnt + 1);
	solve(idx + 1, bits, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		string temp, str;
		cin >> temp >> str;

		for (int j = 0; j < m; ++j)
		{
			if (str[j] == 'Y')
				v[i] |= (1LL << (m - 1 - j));
		}
	}

	solve(0, 0, 0);

	if (maxCnt == 0)
		cout << -1;
	else
		cout << answer;

	return 0;
}