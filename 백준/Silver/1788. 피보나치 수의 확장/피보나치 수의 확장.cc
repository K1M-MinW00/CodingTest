#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> f(1000001, 0);

	if (n >= 1)
	{
		f[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
		}

		cout << 1 << '\n';
		cout << f[n];
	}
	else if (n == 0)
	{
		cout << 0 << '\n' << 0;
	}
	else
	{
		n *= -1;
		f[1] = 1;
		f[2] = -1;

		for (int i = 3; i <= n; ++i)
		{
			f[i] = (f[i - 2] - f[i - 1]) % 1000000000;
		}

		int answer = f[n] > 0 ? 1 : -1;


		cout << answer << '\n' << abs(f[n]);
	}
	return 0;
}