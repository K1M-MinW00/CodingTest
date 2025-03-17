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
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; ++i)
		cin >> v[i].second >> v[i].first;

	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i)
	{
		pq.push(v[i].second);

		if (pq.size() > v[i].first) // pq.size() == 날짜 > 기한
			pq.pop(); // 가장 p 가 적은 강연 pop
	}

	int answer = 0;

	while (pq.size())
	{
		answer += pq.top();
		pq.pop();
	}

	cout << answer;

	return 0;
}