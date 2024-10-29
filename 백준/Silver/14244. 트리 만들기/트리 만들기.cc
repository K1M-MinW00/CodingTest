#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		cout << 0 << ' ' << i << '\n';

	for (int i = m + 1; i < n; ++i)
		cout << i - 1 << ' ' << i << '\n';

	return 0;
}