#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;

		int cnt = 0;


		for (int i = 5; i <= n; i *= 5)
		{
			cnt += n / i;
		}

		cout << cnt << '\n';
	}
	return 0;
}