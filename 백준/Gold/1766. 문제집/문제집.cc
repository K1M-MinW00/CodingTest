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

#define MAX 32001

int prioirty[MAX] = { 0, };
vector<int> seq[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;


	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		prioirty[b]++;
		seq[a].push_back(b);
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; ++i)
	{
		if (prioirty[i] == 0)
			pq.push(i);
	}

	while (pq.size())
	{
		int top = pq.top();
		pq.pop();

		cout << top << ' ';

		for (int next : seq[top])
		{
			prioirty[next]--;
			if (prioirty[next] == 0)
				pq.push(next);
		}
	}

	return 0;
}