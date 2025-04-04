#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <climits>
using namespace std;

int n;
int answer_min = INT_MAX, answer_max = INT_MIN;
vector<int> v;

void solve(int idx, int p, int m, int t, int d, int cur)
{
	if (idx == n)
	{
		answer_min = min(answer_min, cur);
		answer_max = max(answer_max, cur);
		return;
	}

	if (p > 0)
	{
		solve(idx + 1, p - 1, m, t, d, cur + v[idx]);
	}
	if (m > 0)
	{
		solve(idx + 1, p, m - 1, t, d, cur - v[idx]);
	}
	if (t > 0)
	{
		solve(idx + 1, p, m, t - 1, d, cur * v[idx]);
	}
	if (d > 0)
	{
		solve(idx + 1, p, m, t, d - 1, cur / v[idx]);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int p, m, t, d; // plus - minus - times - divide

	cin >> p >> m >> t >> d;

	solve(1, p, m, t, d, v[0]);

	cout << answer_max << '\n' << answer_min;
	return 0;
}