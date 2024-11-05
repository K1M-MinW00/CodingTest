#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		string a;
		cin >> a;
		
		char c;
		int error_b = 0, error_w = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> c;

			if (a[i] == c)
				continue;
			else if (a[i] == 'B' && c != 'B')
				error_b++;
			else if (a[i] == 'W' && c != 'W')
				error_w++;
		}

		cout << error_b + error_w -  min(error_b, error_w) << '\n';
	}

	return 0;
}