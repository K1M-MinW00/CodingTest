#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <climits>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int s = 0, e = 1;
	int answer = INT_MAX;

	while (s < n)
	{
		int d = v[e] - v[s];
		if (d >= m)
		{
			answer = min(answer, d);
			if (d == m)
				break;
			s++;
		}
		else
		{
			e++;
			if (e == n)
				break;
		}
	}

	cout << answer;
	return 0;
}