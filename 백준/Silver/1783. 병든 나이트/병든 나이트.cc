#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int result = 0;
	if (n == 1)
		result = 1;
	else if (n == 2)
	{
		if (m >= 7)
			result = 4;
		else
			result = (m + 1) / 2;
	}
	else
	{
		if (m < 7)
			result = min(4, m);
		else
			result = m - 2;
	}

	cout << result;

	return 0;
}