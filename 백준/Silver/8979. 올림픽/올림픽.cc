#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(n + 1, vector<int>(4));

	int idx;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];

		if (v[i][0] == k)
			idx = i;
	}

	int rank = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (idx == i)
			continue;

		if (v[idx][1] < v[i][1])
			rank++;
		else if (v[idx][1] == v[i][1] && v[idx][2] < v[i][2])
			rank++;
		else if (v[idx][1] == v[i][1] && v[idx][2] == v[i][2] && v[idx][3] < v[i][3])
			rank++;
	}

	cout << rank + 1;

	return 0;
}