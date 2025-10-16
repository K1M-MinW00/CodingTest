#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

vector<int> v, asc;

int binary_search(int k)
{
	int l = 0, r = asc.size() - 1, mid;

	while (l < r)
	{
		mid = l + (r - l) / 2;

		if (asc[mid] >= k)
			r = mid;
		else
			l = mid + 1;
	}

	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	asc.push_back(v[0]);

	for (int i = 1; i < n; ++i)
	{
		if (asc.back() < v[i])
		{
			asc.push_back(v[i]);
		}
		else
		{
			int idx = binary_search(v[i]);
			asc[idx] = v[i];
		}
	}

	cout << asc.size();

	return 0;
}