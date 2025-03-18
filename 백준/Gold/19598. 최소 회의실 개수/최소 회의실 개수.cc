#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
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

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	int m = 1;

	for (int i = 1; i < n; ++i)
	{
		while (pq.size() && pq.top() <= v[i].first)
			pq.pop();
		pq.push(v[i].second);
		m = max(m, (int)pq.size());
	}

	cout << m;

	return 0;
}