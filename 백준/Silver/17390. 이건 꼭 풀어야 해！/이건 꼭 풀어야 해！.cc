#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	v.resize(n + 1);
	v[0] = 0;

	for (int i = 1; i <= n; ++i)
		cin >> v[i];


	sort(v.begin() + 1, v.end());

	int l, r;

	for (int i = 1; i <= n; ++i)
		v[i] += v[i - 1];

	for (int i = 0; i < q; ++i)
	{
		cin >> l >> r;
		cout << v[r] - v[l - 1] << '\n';
	}

	return 0;
}