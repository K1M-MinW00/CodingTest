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
#define N 21

int n;
int l[N], j[N];

int answer = 0;

void solve(int idx, int hp, int joy)
{
	if (hp <= 0)
		return;

	if (idx == n + 1)
	{
		answer = max(joy, answer);
		return;
	}

	solve(idx + 1, hp - l[idx], joy + j[idx]);
	solve(idx + 1, hp, joy);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> l[i];

	for (int i = 1; i <= n; ++i)
		cin >> j[i];

	solve(0, 100, 0);

	cout << answer << '\n';

	return 0;
}