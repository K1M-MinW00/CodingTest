#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
using namespace std;

vector<int> v, sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;

	int c = 1;

	while (c < k)
		c <<= 1;

	cout << c << ' ';

	int cnt = 0;

	while (k > 0)
	{
		if (k < c)
		{
			c >>= 1;
			cnt++;
		}
		else
		{
			k -= c;
		}
	}

	cout << cnt;
	return 0;
}