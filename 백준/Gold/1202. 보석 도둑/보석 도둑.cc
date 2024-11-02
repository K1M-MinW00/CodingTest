#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<pair<int, int>> pq;

	int n, k;
	cin >> n >> k;


	vector<pair<int, int>> j(n);
	vector<int> b(k);

	for (int i = 0; i < n; ++i)
	{
		cin >> j[i].first >> j[i].second;
	}

	for (int i = 0; i < k; ++i)
	{
		cin >> b[i];
	}

	sort(j.begin(), j.end());
	sort(b.begin(), b.end());

	long long result = 0;

	int idx = 0;
	for (auto bag : b)
	{
		while (idx < n && j[idx].first <= bag)
		{
			pq.push({ j[idx].second , j[idx].first });
			idx++;
		}

		if (!pq.empty())
		{
			result += pq.top().first;
			pq.pop();
		}
	}

	cout << result;

	return 0;
}