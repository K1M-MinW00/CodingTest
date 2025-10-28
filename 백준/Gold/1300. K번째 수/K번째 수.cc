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

int n, k;

void bin_search()
{
	int l = 1, r = k, mid;
	int answer = 0;

	while (l <= r)
	{
		mid = (l + r) / 2;

		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum += min(mid / i, n);
		}

		if (sum < k)
		{
			l = mid + 1;
		}
		else
		{
			answer = mid;
			r = mid - 1;
		}
	}
	cout << answer;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	bin_search();

	return 0;
}