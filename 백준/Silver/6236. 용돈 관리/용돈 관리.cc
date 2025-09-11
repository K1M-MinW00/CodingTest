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
#define N 100001

int n, m, l, r;
int v[N];

bool check(int mid)
{
	int cnt = 1, money = mid;

	for (int i = 0; i < n; ++i)
	{
		if (money < v[i])
		{
			money = mid;
			cnt++;
		}
		money -= v[i];
	}
	return cnt <= m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		l = max(l, v[i]);
	}

	r = 10000 * N;
	
	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (check(mid) == true)
		{
			r = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
	}

	cout << l;

	return 0;
}