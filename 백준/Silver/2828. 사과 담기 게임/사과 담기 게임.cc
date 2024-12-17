#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, l, r, t, answer = 0;
	cin >> n >> m >> k;

	l = 1;
	for (int i = 0; i < k; ++i)
	{
		r = l + m - 1;
		cin >> t;

		if (t >= l && t <= r)
			continue;
		else
		{
			if (t < l)
			{
				answer += (l - t);
				l = t;
			}
			else
			{
				l += (t - r);
				answer += (t - r);
			}
		}
	}
	cout << answer;
	return 0;
}