#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (n % i == 0)
		{
			cnt++;

			if (cnt == k)
			{
				cout << i;
				return 0;
			}
		}
	}

	if (cnt < k)
		cout << 0;

	return 0;
}