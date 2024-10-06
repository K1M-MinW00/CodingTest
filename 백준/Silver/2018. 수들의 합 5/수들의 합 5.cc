#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int s = 1, e = 1;

	int answer = 0;

	int sum = 0;

	while (s <= e && e <= n)
	{
		if (sum < n)
			sum += e++;

		else if (sum > n)
			sum -= s++;

		else
		{
			answer++;
			sum -= s++;
		}
	}

	cout << answer + 1;
	return 0;
}