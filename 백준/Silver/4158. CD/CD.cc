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


	int n, m, t, l, r, mid, answer;

	while (1)
	{
		cin >> n >> m;

		if (!n && !m)
			break;

		vector<int> v;
		v.clear();

		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			v.push_back(t);
		}

		answer = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> t;

			l = 0, r = n - 1;

			while (l <= r)
			{
				mid = (l + r) / 2;

				if (v[mid] == t)
				{
					answer++;
					break;
				}

				else if (v[mid] < t)
					l = mid + 1;
				else
					r = mid - 1;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}