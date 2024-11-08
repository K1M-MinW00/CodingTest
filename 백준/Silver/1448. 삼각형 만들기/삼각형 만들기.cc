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

	vector<int>v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(),greater<int>());

	int idx = 0;

	for (int i = 0; i < n - 2; ++i)
	{
		int a = v[i];
		int b = v[i+1];
		int c = v[i + 2];

		if (a < b + c)
		{
			cout << a + b + c;
			return 0;
		}
		else
			continue;
	}

	cout << -1;
	return 0;
}