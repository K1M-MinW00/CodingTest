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

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	if (n == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	sort(v.begin(), v.end());

	int l = 0, r = n - 1;
	int sum = 0, answer = 0;

	while (l < r)
	{
		sum = v[l] + v[r];

		if (sum == m)
		{
			answer++;
			l++;
			r--;
		}
		else if (sum < m)
		{
			l++;
		}
		else
			r--;
	}

	cout << answer;
	return 0;
}