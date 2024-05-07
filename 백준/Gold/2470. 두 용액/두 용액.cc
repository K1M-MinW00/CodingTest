#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int s = 0, e = n - 1;

	long long minV = 2000000000;

	pair<int, int> p;

	while (s < e)
	{
		long long temp = v[s] + v[e];

		if (temp == 0)
		{
			p.first = s;
			p.second = e;
			break;
		}
		else if (abs(temp) < minV)
		{
			minV = abs(temp);
			p.first = s;
			p.second = e;
		}

		if (temp < 0)
			++s;
		else
			--e;
	}

	cout << v[p.first] << ' ' << v[p.second];

	return 0;
}