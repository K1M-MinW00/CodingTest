#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;

int n, m, k, t, answer;
int v[51];
vector<int> person;
vector<int> party[51];

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
	{
		v[parent_a] = parent_b;
	}
	else if (parent_a < parent_b)
	{
		v[parent_b] = parent_a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	person.resize(k);
	for (int i = 0; i < k; ++i)
		cin >> person[i];

	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		party[i].resize(t);
		for (int j = 0; j < t; ++j)
			cin >> party[i][j];
	}
	answer = m;

	for (int i = 1; i <= n; ++i)
		v[i] = i;


	for (int i = 0; i < m; ++i)
	{
		int s = party[i][0];

		for (int j = 0; j < party[i].size(); ++j)
		{
			int e = party[i][j];
			Union(s, e);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		bool go = true;

		for (int j = 0; j < party[i].size(); ++j)
		{
			if (!go)
				break;

			int s = party[i][j];
			for (int k = 0; k < person.size(); ++k)
			{
				int e = person[k];
				if (Find(s) == Find(e))
				{
					go = false;
					break;
				}
			}
		}

		if (!go)
			answer--;
	}
	cout << answer;

	return 0;
}