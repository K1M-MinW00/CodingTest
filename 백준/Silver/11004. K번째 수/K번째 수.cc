#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int n, k;
vector<int> v;

int partition(int s, int e)
{
	if (s + 1 == e)
	{
		if (v[s] > v[e])
			swap(v[s], v[e]);
		return e;
	}

	int m = (s + e) / 2;
	swap(v[s], v[m]);
	int pivot = v[s];
	int l = s + 1, r = e;

	while (l <= r)
	{
		while (pivot < v[r] && r > 0)
			r--;

		while (pivot > v[l] && l < n - 1)
			l++;

		if (l <= r)
			swap(v[l++], v[r--]);
	}

	v[s] = v[r];
	v[r] = pivot;
	return r;
}

void quick_sort(int s, int e, int k)
{
	int pivot = partition(s, e);

	if (pivot == k)
		return;

	else if (k < pivot)
		quick_sort(s, pivot - 1, k);
	else
		quick_sort(pivot + 1, e, k);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	quick_sort(0, n - 1, k - 1);

	cout << v[k - 1];
	return 0;
}