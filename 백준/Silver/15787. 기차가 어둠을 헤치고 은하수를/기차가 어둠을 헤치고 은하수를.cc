#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include<bitset>
#include <unordered_map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int op, i, x;

	vector<int> v(n + 1);

	for (int k = 0; k < m; ++k)
	{
		cin >> op >> i;

		if (op <= 2)
			cin >> x;


		if (op == 1)
		{
			v[i] |= (1 << x);
		}
		else if (op == 2)
		{
			v[i] &= ~(1 << x);
		}
		else if (op == 3)
		{
			v[i] <<= 1;
			v[i] &= ((1 << 21) - 1);
		}
		else
		{
			v[i] >>= 1;
			v[i] &= ~1;
		}
	}

	vector<bool> visited(1 << 21);

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (visited[v[i]] == false)
			cnt++;
		visited[v[i]] = true;
	}

	cout << cnt;

	return 0;
}