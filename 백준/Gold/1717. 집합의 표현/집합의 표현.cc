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
#include <tuple>

using namespace std;

int n, m;
vector<int> parent;

int find(int a)
{
	if (parent[a] == a)
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

bool check(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return true;

	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 0; i <= n; ++i)
		parent[i] = i;

	int op, a, b;

	for (int i = 0; i < m; ++i)
	{
		cin >> op >> a >> b;

		if (op == 0)
		{
			Union(a, b);
		}
		else if (op == 1)
		{
			if (check(a, b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}