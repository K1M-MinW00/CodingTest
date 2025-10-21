#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> v(n + 1);

	long long answer;

	if (n <= 3)
		answer = 1;

	else
	{
		v[1] = v[2] = v[3] = 1;

		for (int i = 4; i <= n; ++i)
			v[i] = v[i - 1] + v[i - 3];

		answer = v[n];
	}

	cout << answer;

	return 0;
}