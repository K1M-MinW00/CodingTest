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
#define N 100005

int n;
int v[N];

void solve()
{
	int l = 1, r = 1, answer = 1;

	for (int i = 1; i < n; ++i)
	{
		if (v[i] >= v[i + 1])
		{
			l++;
		}
		else
		{
			l = 1;
		}

		if (v[i] <= v[i + 1])
		{
			r++;
		}
		else
		{
			r = 1;
		}
		answer = max(answer, max(l, r));
	}
	cout << answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}

	solve();

	return 0;
}