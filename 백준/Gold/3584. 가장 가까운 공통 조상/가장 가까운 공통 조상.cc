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
#define N 10001

int parent[N];
bool visited[N];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, a, b;
		cin >> n;

		for (int i = 1; i <= n; ++i)
		{
			visited[i] = false;
			parent[i] = -1;
		}

		for (int i = 0; i < n - 1; ++i)
		{
			cin >> a >> b;
			parent[b] = a;
		}

		cin >> a >> b;

		visited[a] = true;

		while (a != parent[a])
		{
			visited[a] = true;
			a = parent[a];
		}

		while (b != parent[b])
		{
			if (visited[b] == true)
			{
				cout << b << '\n';
				break;
			}

			b = parent[b];
		}
	}

	return 0;
}