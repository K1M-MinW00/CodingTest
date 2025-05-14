#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int i, j, k;
	vector<int> v(n + 1);

	while (m--)
	{
		cin >> i >> j >> k;

		for (int s = i; s <= j; ++s)
			v[s] = k;
	}

	for (int i = 1; i <= n; ++i)
		cout << v[i] << ' ';

	return 0;
}