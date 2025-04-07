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

using namespace std;

int n, d;
vector<pair<int, int>> v[10001];

int answer = INT_MAX;

void solve()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (q.size())
	{
		int cur = q.front().first;
		int cur_d = q.front().second;
		q.pop();

		int next, next_d;

		if (v[cur].size()) // 지름길 O
		{
			for (auto road : v[cur])
			{
				next = road.first, next_d = cur_d + road.second;

				if (next > d)
					continue;
				else if (next == d)
				{
					answer = min(answer, next_d);
				}
				else
				{
					q.push({ next,next_d });
				}
			}
		}

		// 지름길 X , 일반 도로
		next = cur + 1, next_d = cur_d + 1;

		if (next > d)
			continue;
		else if (next == d)
		{
			answer = min(answer, next_d);
		}
		else
		{
			q.push({ next,next_d });
		}
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> d;

	int s, e, l;

	for (int i = 0; i < n; ++i)
	{
		cin >> s >> e >> l;
		v[s].push_back({ e,l });
	}

	solve();

	cout << answer;
	return 0;
}