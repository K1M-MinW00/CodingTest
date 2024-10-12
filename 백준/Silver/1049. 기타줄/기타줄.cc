#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;

	for (int i = 0; i < m; ++i)
	{
		int package, each;
		cin >> package >> each;

		a = min(a, package);
		b = min(b, each);
	}

	int answer = min((n / 6 + 1) * a, (n / 6) * a + n % 6 * b);
	answer = min(answer, n * b);

	cout << answer;

	return 0;
}