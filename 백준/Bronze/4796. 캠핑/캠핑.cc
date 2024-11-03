#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l, p, v;

	int idx = 1;
	while (1)
	{
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0)
			break;

		int q = v / p;
		int r = v % p;

		int answer = l * q + min(l,r);
		cout << "Case " << idx++ << ": " << answer << '\n';
	}


	return 0;
}