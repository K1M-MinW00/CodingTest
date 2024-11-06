#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	priority_queue<int, vector<int>, greater<int>> pq;
	int a, b;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)
			pq.pop();
	}

	cout << pq.size();

	return 0;
}