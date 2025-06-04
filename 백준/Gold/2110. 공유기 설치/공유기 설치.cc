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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int s = 0, e = v[n-1];
	int mid, cnt, ret = 0;

	while (s <= e)
	{
		cnt = 1, mid = (s + e) / 2;

		int cur = v[0];

		for (int i = 1; i < n; ++i)
		{
			int next = v[i];

			if (next - cur >= mid)
			{
				cnt++;
				cur = next;
			}
		}

		if (cnt >= c)
		{
			ret = mid;
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}
	}

	cout << ret;
	return 0;
}