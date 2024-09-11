#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());


	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += v[i] * (n - i);
	}

	cout << sum;

	return 0;
}