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

int n, k, cnt = 0;
int answer = -1;

int* tmp;

void merge(vector<int>& a, int p, int q, int r)
{
	int i = p, j = q + 1, t = 0;

	while (i <= q && j <= r)
	{
		if (a[i] <= a[j])
		{
			tmp[t++] = a[i++];
		}
		else
		{
			tmp[t++] = a[j++];
		}
	}

	while (i <= q)
	{
		tmp[t++] = a[i++];
	}

	while (j <= r)
	{
		tmp[t++] = a[j++];
	}

	i = p, t = 0;

	while (i <= r)
	{
		a[i++] = tmp[t++];

		if (++cnt == k)
		{
			answer = a[i - 1];
		}
	}
}

void merge_sort(vector<int>& a, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	tmp = new int[n + 1];

	merge_sort(v, 0, n - 1);

	delete(tmp);
	cout << answer;

	return 0;
}