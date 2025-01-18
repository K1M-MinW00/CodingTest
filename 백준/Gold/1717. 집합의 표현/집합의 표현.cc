#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


int n, m;
vector<int> v;

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
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1);

	for (int i = 0; i <= n; ++i)
		v[i] = i;

	int a, b, op;

	for (int i = 0; i < m; ++i)
	{
		cin >> op >> a >> b;

		if (op == 0)
		{
			Union(a, b);
		}
		else
		{
			if (Find(a) == Find(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}