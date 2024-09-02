#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<bool> S(21, 0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string query;
		int m;

		cin >> query;

		if (query == "add")
		{
			cin >> m;
			S[m] = true;
		}

		else if (query[0] == 'r')
		{
			cin >> m;
			S[m] = false;
		}

		else if (query[0] == 'c')
		{
			cin >> m;
			if (S[m])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		else if (query[0] == 't')
		{
			cin >> m;
			if (S[m])
				S[m] = false;
			else
				S[m] = true;
		}

		else if (query == "all")
		{
			for (int i = 1; i <= 20; ++i)
				S[i] = true;
		}
		else if (query[0] == 'e')
		{
			for (int i = 1; i <= 20; ++i)
				S[i] = false;
		}
	}

	return 0;
}