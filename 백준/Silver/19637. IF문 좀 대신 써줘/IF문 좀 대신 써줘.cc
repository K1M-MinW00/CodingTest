#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;

vector<string> s;
vector<int> v;

int bin(int x)
{
	int mid = 0, start = 0, end = n - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (x <= v[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}

	if (x > v[mid])
		return mid + 1;
	else
		return mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	v.resize(n);
	s.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> s[i] >> v[i];

	int x;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;

		int idx = bin(x);
		cout << s[idx] << '\n';
	}
	return 0;
}