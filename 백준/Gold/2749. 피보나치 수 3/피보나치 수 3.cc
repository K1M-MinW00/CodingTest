#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;
#define D 1,000,000

const int m = 1000000;
const int p = 15 * (m / 10);

int f[p];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;

	f[0] = 0, f[1] = 1;

	if (n <= 1)
		cout << f[n];

	else
	{
		for (int i = 2; i < p; ++i)
		{
			f[i] = (f[i - 1] + f[i - 2]) % m;
		}

		cout << f[n % p];
	}

	return 0;
}