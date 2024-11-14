#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, num, m, s, e;
	cin >> n;

	vector<int> v(n + 1);


	for (int i = 1; i <= n; ++i)
	{
		cin >> num;
		v[i] = v[i - 1] + num;
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> s >> e;

		if (s == 1)
			cout << v[e] << '\n';
		else
			cout << v[e] - v[s - 1] << '\n';
	}

	return 0;
}