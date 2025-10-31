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

vector<tuple<int, int, int>> v[10];
bool visited[10];
long long d[10];

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	cin >> k;

	sort(v.begin(), v.end());

	int s = 0, e = 0;

	for (int i = 0; i < n; ++i)
	{
		if (k < v[i])
		{
			if (i > 0)
				s = v[i - 1];
			e = v[i];
			break;
		}
	}

	if (s == k)
	{
		cout << 0;
		return 0;
	}

	int cnt = 0;

	for (int i = min(s + 1, k); i <= k; ++i)
	{
		for (int j = max(i + 1, k); j < e; ++j)
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}