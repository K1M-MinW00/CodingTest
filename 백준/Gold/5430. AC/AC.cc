#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int test_case;
	cin >> test_case;


	string op;
	int n;
	char left, right, comma;

	for (int t = 0; t < test_case; ++t)
	{
		cin >> op;
		cin >> n;

		cin >> left;

		vector<int> v;

		if (n != 0)
			v.resize(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];

			if (i != n - 1)
				cin >> comma;
		}
		cin >> right;

		int start = 0, end = n;
		bool dir = true;
		bool find = true;

		for (int i = 0; i < op.length(); ++i)
		{
			if (op[i] == 'R')
			{
				dir = !dir;
			}
			else if (op[i] == 'D')
			{
				if (dir)
					start++;
				else
					end--;

				if (start > end)
				{
					find = false;
					break;
				}
			}
		}

		if (find)
		{
			cout << '[';
			if (dir)
			{
				for (int i = start; i < end; ++i)
				{
					cout << v[i];
					if (i != end - 1)
						cout << ',';
				}
			}
			else
			{
				for (int i = end - 1; i >= start; --i)
				{
					cout << v[i];
					if (i != start)
						cout << ',';
				}
			}
			cout << "]\n";
		}
		else
			cout << "error\n";
	}

	return 0;
}