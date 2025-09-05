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
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}

		int mx = -1;
		long sum = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			mx = max(mx, v[i]);
			sum += (mx - v[i]);
		}

		cout << sum << '\n';
	}

	return 0;
}