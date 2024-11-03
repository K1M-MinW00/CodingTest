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

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int total = 0;

	for (int i = n - 1; i > 0; i--)
	{
		int cur = v[i];

		for (int j = 0; j < i; ++j)
		{
			if (v[j] < cur)
			{
				continue;
			}
			else
			{
				total += v[j] - cur + 1;
				v[j] = cur - 1;
			}
		}
	}

	cout << total;
	return 0;
}