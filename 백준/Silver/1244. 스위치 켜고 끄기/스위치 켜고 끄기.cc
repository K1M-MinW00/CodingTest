#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<bool> v(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		bool input;
		cin >> input;
		v[i] = input;
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int s, k;
		cin >> s >> k;

		if (s == 1) // 남
		{
			for (int i = k; i <= n; i += k)
				v[i] = !v[i];
		}
		else // 여
		{
			v[k] = !v[k];
			for (int i = 1; i + k <= n && k - i >= 1; ++i)
			{
				int left = k - i;
				int right = k + i;

				if (v[left] == v[right])
				{
					v[left] = !v[left];
					v[right] = !v[right];
				}
				else
					break;
			}
		}
	}


	for (int i = 1; i <= n; ++i)
	{
		cout << v[i];

		if (i % 20 == 0)
			cout << '\n';
		else
			cout << ' ';
	}

	return 0;
}