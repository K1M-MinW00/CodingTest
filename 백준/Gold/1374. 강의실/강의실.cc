#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


priority_queue<long long, vector<long long>, greater<long long>> pq;
vector <pair<long long, long long>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	long long num, s, e;
	int answer = 1;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> num >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		int start = v[i].first;
		int end = v[i].second;

		if (pq.empty())
			pq.push(end);
		else
		{
			if (pq.top() > start)
				answer++;
			else
				pq.pop();
			pq.push(end);
		}
	}

	cout << answer;

	return 0;
}