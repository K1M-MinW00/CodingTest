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
#include <tuple>
#include <sstream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> m >> n;

	vector<bool> v(n + 1, true);

	v[1] = false;

	for (int i = 2; i * i <= n; ++i)
	{
		if (v[i] == false)
			continue;

		for (int j = i + i; j <= n; j += i)
		{
			v[j] = false;
		}
	}

	for (int i = m; i <= n; ++i)
	{
		if (v[i])
			cout << i << '\n';
	}
	return 0;
}