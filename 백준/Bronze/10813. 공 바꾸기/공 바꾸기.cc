#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i)
		v[i] = i;

	int i, j;
	while (m--)
	{
		cin >> i >> j;

		int tmp = v[j];
		v[j] = v[i];
		v[i] = tmp;
	}

	for (int i = 1; i <= n; ++i)
		cout << v[i] << ' ';

	return 0;
}