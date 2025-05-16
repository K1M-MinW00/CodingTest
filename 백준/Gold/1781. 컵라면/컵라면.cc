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

	vector<pair<int, int>> v;
	int d, c;

	for (int i = 0; i < n; ++i)
	{
		cin >> d >> c;
		v.push_back({ d,c });
	}

	sort(v.begin(), v.end());

	priority_queue<int,vector<int>,greater<int>> pq;

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += v[i].second;
		pq.push(v[i].second);

		if (pq.size() > v[i].first)
		{
			answer -= pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}