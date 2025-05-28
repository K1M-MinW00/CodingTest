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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	long long answer = 987654321;

	for (int i = 1; i < (1 << n); ++i)
	{
		long long s_sum = 1, b_sum = 0, sub;

		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				s_sum *= v[j].first;
				b_sum += v[j].second;
			}
		}

		sub = abs(s_sum - b_sum);

		answer = min(answer, sub);
	}

	cout << answer;
	return 0;
}