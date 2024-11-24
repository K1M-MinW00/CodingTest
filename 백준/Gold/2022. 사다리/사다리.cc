#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double a, b, c;
vector<int> v;

double bin()
{
	double l = 0, r = min(a, b), mid, result = 0;

	while (r - l > 0.000001)
	{
		mid = (l + r) / 2.0;

		double xy = sqrt(a * a - mid * mid) * sqrt(b * b - mid * mid);
		double xPlusy = sqrt(a * a - mid * mid) + sqrt(b * b - mid * mid);

		double _c = xy / xPlusy;

		if (_c >= c)
		{
			result = mid;
			l = mid;
		}
		else
			r = mid;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << fixed;
	cout.precision(3);
	cout << bin();

	return 0;
}