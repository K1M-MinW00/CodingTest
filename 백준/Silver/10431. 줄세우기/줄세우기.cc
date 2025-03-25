#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int p, t;
	cin >> p;

	while (p--)
	{
		cin >> t;

		vector<int> v(20);
		for (int i = 0; i < 20; ++i)
			cin >> v[i];

		int cnt = 0;

		for (int i = 0; i < 20; ++i)
		{
			for (int j = i; j < 20; ++j)
			{
				if (v[j] < v[i])
					cnt++;
			}
		}

		cout << t << ' ' << cnt << '\n';
	}

	return 0;
}