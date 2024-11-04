#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;

	int min = abs(a - b);
	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;

		temp -= b;
		temp = abs(temp);

		if (temp < min)
		{
			min = temp;
			cnt = 1;
		}
	}

	cout << cnt + min;

	return 0;
}