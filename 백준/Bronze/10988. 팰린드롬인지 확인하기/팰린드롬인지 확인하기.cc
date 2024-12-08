#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int n = s.length();
	for (int i = 0; i <= n / 2; ++i)
	{
		if ((i <= n / 2) && s[i] == s[n - i - 1])
			continue;
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}