#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		v[i] = i;
	}

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			v[i] = min(v[i], v[i - j * j] + 1);
		}

	}

	cout << v[n];

	return 0;
}