#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int remain;
		cin >> remain;

		int coins[] = {25,10,5,1 };

		for (int j = 0; j < 4; ++j)
		{
			int cnt = remain / coins[j];
			remain %= coins[j];
			cout << cnt << ' ';
		}

		cout << '\n';
	}


	return 0;
}