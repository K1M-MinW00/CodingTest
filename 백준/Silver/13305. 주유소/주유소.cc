#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> c, d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	c.resize(n + 1); d.resize(n + 1);

	for (int i = 1; i < n; ++i)
		cin >> d[i];

	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	int min = INT_MAX;
	long long answer = 0;

	for (int i = 1; i < n; ++i)
	{
		if (c[i] < min) min = c[i];
		answer += (long long)min * (long long)d[i];
	}

	cout << answer;
	return 0;
}