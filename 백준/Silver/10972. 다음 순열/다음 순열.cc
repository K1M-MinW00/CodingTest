#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> first;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	first = v;
	sort(first.begin(), first.end());

	next_permutation(v.begin(), v.end());

	if (v != first)
		for (int i : v)
			cout << i << ' ';
	else
		cout << -1;
	return 0;
}