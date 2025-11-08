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
#include <unordered_set>
#include <bitset>
#include <tuple>

using namespace std;

vector<int> parent;

typedef tuple<int, int, int> edge;

int find(int a)
{
	if (a == parent[a])
		return a;

	return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
		parent[b] = a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 1; i <= n; ++i)
		parent[i] = i;

	priority_queue<edge, vector<edge>, greater<edge>> pq;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		pq.push({ c,a,b }); // 가중치 기준 오름차순 정렬을 위해
	}

	int edge_cnt = 0;
	int weight = 0;

	while (edge_cnt < n - 1)
	{
		edge cur = pq.top();
		pq.pop();

		int w = get<0>(cur);
		int s = get<1>(cur);
		int e = get<2>(cur);

		if (find(s) != find(e))
		{
			weight += w;
			edge_cnt++;
			Union(s, e);
		}
	}

	cout << weight;

	return 0;
}