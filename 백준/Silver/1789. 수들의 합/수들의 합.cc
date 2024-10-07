#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long  s, n = 0;

	cin >> s;

	while (s > 0)
	{
		n++;
		s -= n;
	}

	if (s < 0)
		n--;

	cout << n;

	return 0;
}