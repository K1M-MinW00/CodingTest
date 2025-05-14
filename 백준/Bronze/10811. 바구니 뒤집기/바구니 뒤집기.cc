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

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; ++i)
		v[i] = i;

	int i, j;

	while (m--)
	{
		cin >> i >> j;

		int cnt = 0;
		for (int idx = i; idx <= (i + j) / 2; ++idx)
		{
			int tmp = v[idx];
			v[idx] = v[j - cnt];
			v[j - cnt] = tmp;
			cnt++;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << v[i] << ' ';

	return 0;
}