#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(m);

	for (int i = 0; i < m; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int price = 0;
	int total = 0;

	for (int i = 0; i < m; ++i)
	{
		int sum = 0;

		sum = v[i] * min(n,(m - i));

		if (sum >= total)
		{
			price = v[i];
			total = sum;
		}
	}

	cout << price << ' ' << total;
	return 0;
}