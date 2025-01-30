#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		vector<string> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		sort(v.begin(), v.end());

		bool answer = true;

		for (int i = 0; i < n - 1; ++i)
		{
			string cur = v[i];
			string next = v[i + 1];

			if (cur.length() > next.length())
				continue;

			if (cur == next.substr(0, cur.length()))
			{
				answer = false;
				break;
			}
		}

		if (answer)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}