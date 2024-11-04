#include <iostream>
#include <vector>
#include <algorithm>

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

	sort(v.begin(), v.end(),greater<int>());

	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i % 3 != 2)
			total += v[i];
	}

	cout << total;

	return 0;
}