#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <regex>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int mid = (n - 1) / 2;

	cout << v[mid];


	return 0;
}