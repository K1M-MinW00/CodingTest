#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	while (cin >> a >> b)
	{
		int idx = 0;

		string temp;

		for (int i = 0; i < b.length(); ++i)
		{
			if (idx < a.length() && b[i] == a[idx])
			{
				temp += b[i];
				idx++;
			}
		}
		if (temp == a)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}

	return 0;
}