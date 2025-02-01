#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <regex>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	regex pattern("(100+1+|01)+");

	string str;
	while (n--)
	{
		cin >> str;

		if (regex_match(str, pattern))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}