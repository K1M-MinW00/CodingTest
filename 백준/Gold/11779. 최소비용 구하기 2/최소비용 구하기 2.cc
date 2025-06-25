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
#include <bitset>

using namespace std;
#define MAX 10001
int n, m, s, e;

vector<vector<pair<int, int>>> v;
vector<int> D;
vector<int> R;

void solve()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	D[s] = 0;

	while (pq.size())
	{
		int cnt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

        if(cur == e)
            break;
        
		for (int i = 0; i < v[cur].size(); ++i)
		{
			int next = v[cur][i].first;

			if (D[next] > cnt + v[cur][i].second)
			{
				R[next] = cur;
				D[next] = cnt + v[cur][i].second;
				pq.push({ D[next],next });
			}
		}
	}

	cout << D[e] << '\n';

	int temp = e;
	vector<int> answer;

	while (temp)
	{
		answer.push_back(temp);
		temp = R[temp];
	}

	cout << answer.size() << '\n';
	reverse(answer.begin(), answer.end());

	for (int i : answer)
		cout << i << ' ';

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;

	int a, b, c;

	v.resize(n + 1);
	D.resize(n + 1, INT_MAX);
	R.resize(n + 1);

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		// v[b].push_back({ a,c });
	}

	cin >> s >> e;

	solve();

	return 0;
}