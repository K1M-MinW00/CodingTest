#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
using namespace std;

int n, m;
vector<int> v;
int graph[201][201];

int Find(int a)
{
	if (v[a] == a)
		return a;

	return v[a] = Find(v[a]);
}

void Union(int a, int b)
{
	int parent_a = Find(a);
	int parent_b = Find(b);

	if (parent_a > parent_b)
		v[parent_a] = parent_b;
	else
		v[parent_b] = parent_a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);

	for (int i = 1; i <= n; ++i)
		v[i] = i;

	int temp;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> temp;
			if (temp == 1)
				Union(i, j);
		}


	int start, cnt = 0;
	cin >> start;
	start = Find(start);

	for (int i = 1; i < m; ++i)
	{
		cin >> temp;
		if (Find(temp) == start)
			cnt++;
		else
			break;
		start = Find(temp);
	}

	if (cnt == m - 1)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
