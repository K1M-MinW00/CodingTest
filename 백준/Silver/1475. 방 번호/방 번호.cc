#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int num[10] = { 0, };

	for (int i = 0; i < str.length(); ++i)
		num[str[i] - '0']++;

	int max = -1;
	int idx;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 9 || i == 6)
			continue;

		if (num[i] > max)
			max = num[i];
	}

	int sum = (num[6] + num[9] + 1) / 2;

	if (max > sum)
		cout << max;
	else
		cout << sum;

	return 0;
}