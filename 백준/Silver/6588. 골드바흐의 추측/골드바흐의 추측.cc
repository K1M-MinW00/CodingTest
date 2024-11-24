#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v(1000001, 0);
	vector<int> op; // odd Prime
	for (int i = 2; i <= 1000000; ++i)
	{
		if (v[i] == 0)
		{
			v[i] = 1;
			op.push_back(i);
			for (int j = i + i; j <= 1000000; j += i)
			{
				if (v[j] == 0)
				{
					v[j] = 2;
				}
			}
		}
	}

	int n;

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;
		bool find = false;

		for (int i = 0; i < op.size(); ++i)
		{
			int a = op[i];
			int b = n - a;

			if (v[b] == 1)
			{
				cout << n << " = " << a << " + " << b << '\n';
				find = true;
				break;
			}
		}

		if (!find)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}

	return 0;
}