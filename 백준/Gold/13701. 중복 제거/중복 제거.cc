#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	bitset<33554432> set;

	while (1)
	{
		int n;
		cin >> n;

		if (cin.eof())
			break;

		if (!set[n])
		{
			set[n] = 1;
			cout << n << ' ';
		}
	}

	return 0;
}