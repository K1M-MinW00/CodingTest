#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
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

	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < n; ++i)
		cout << v[i] << '\n';
	return 0;
}