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

	int n, m;
	cin >> n >> m;

	int k, num;
	vector<queue<int>> q(200001);
	vector<int> A(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> num;
			q[num].push(i);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> num;

		if (q[num].empty())
			continue;

		int idx = q[num].front();
		q[num].pop();
		A[idx]++;
	}

	for (int i = 0; i < n; ++i)
		cout << A[i] << ' ';

	return 0;
}