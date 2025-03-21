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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	int p = 0, maxV = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		p += v[i];
		maxV = max(v[i], maxV);
	}

	int answer = p;
	int s = maxV, e = p, mid;

	// cout << "s = " << s << ", e = " << e << '\n';

	while (s <= e)
	{
		mid = (s + e) / 2;
		// cout << mid << ':' << '\n';

		int cnt = 0, sum = 0, start_idx = 1;

		for (int i = 1; i <= n; ++i)
		{
			int temp = sum + v[i];

			if (temp > mid)
			{
				cnt++;
				// cout << start_idx << '~' << i - 1 << " = " << sum << '\n';
				sum = v[i];
				start_idx = i;

				if (i == n)
				{
					cnt++;
					// cout << start_idx << '~' << i << " = " << temp << '\n';
				}
			}
			else if (temp == mid)
			{
				cnt++;
				// cout << start_idx << '~' << i << " = " << temp << '\n';
				sum = 0;
				start_idx = i + 1;
			}
			else
			{
				sum = temp;

				if (i == n)
				{
					cnt++;
					// cout << start_idx << '~' << i << " = " << temp << '\n';
				}
			}
		}

		// cout << "total cnt = " << cnt << "\n\n";
		if (cnt <= m)
		{
			e = mid - 1;
			answer = min(answer, mid);
		}
		else
			s = mid + 1;
	}

	cout << answer;
	return 0;
}