#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, x;
		cin >> n;

		set<int> s1;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			s1.insert(x);
		}

		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> x;

			if (s1.find(x) != s1.end())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}