#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> S(n + 1, 0);

	for (int idx = 1; idx <= n; ++idx)
	{
		int temp;
		cin >> temp;
		S[idx] = S[idx - 1] + temp;
	}

	int i, j;

	for (int idx = 0; idx < m; ++idx)
	{
		cin >> i >> j;

		cout << S[j] - S[i - 1] << '\n';
	}

	return 0;
}