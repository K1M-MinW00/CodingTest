#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, k, sum = 0;
	cin >> m;

	vector<int> v(m);

	for (int i = 0; i < m; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	cin >> k;

	vector<double> p(m);
	double ans = 0;

	for (int i = 0; i < m; ++i)
	{
		if (v[i] >= k)
			p[i] = 1.0;

		for (int j = 0; j < k; ++j)
			p[i] *= (double)(v[i] - j) / (sum - j);

		ans += p[i];
	}

	cout << fixed;
	cout.precision(9);
	cout << ans;

	return 0;
}