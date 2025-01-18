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
	else if (parent_a < parent_b)
		v[parent_b] = parent_a;
	else
	{
		v[parent_a] = 0;
		v[parent_b] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (1)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		v.resize(n + 1);

		for (int i = 1; i <= n; ++i)
			v[i] = i;

		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			Union(a, b);
		}

		int answer = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (v[i] == i)
				answer++;
		}

		cout << "Case " << t++ << ": ";

		if (answer == 1)
			cout << "There is one tree." << '\n';
		else if (answer > 1)
			cout << "A forest of " << answer << " trees." << '\n';
		else
			cout << "No trees." << '\n';


	}
	return 0;
}
