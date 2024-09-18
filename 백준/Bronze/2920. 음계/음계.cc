#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bool isAscending = true;
	bool isDescending = true;

	for (int i = 1; i <= 8; ++i)
	{
		int num;
		cin >> num;

		if (num == i)
		{
			isDescending = false;
		}
		else if (num == 9 - i)
		{
			isAscending = false;
		}
		else
		{
			isAscending = false;
			isDescending = false;
		}
	}

	if (isDescending)
		cout << "descending";
	else if (isAscending)
		cout << "ascending";
	else
		cout << "mixed";

	return 0;
}