#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

int n;

void solve()
{
	int sum = 1;
	vector<int> v;

	for (int i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
		{
			sum += i;
			v.push_back(i);

			if (i != (n / i))
			{
				sum += (n / i);
				v.push_back((n / i));
			}
		}
	}

	if (sum == n)
	{
		cout << n << " = 1";

		sort(v.begin(), v.end());
		for (int d : v)
			cout << " + " << d;
	}
	else
		cout << n << " is NOT perfect.";
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	while (1)
	{
		cin >> n;

		if (n == -1)
			break;

		solve();
	}
	return 0;
}