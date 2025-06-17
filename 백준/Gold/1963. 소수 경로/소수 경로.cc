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
#define MAX 10000

int a, b;
bool visited[MAX];
bool prime[MAX];

void isPrime()
{
	memset(prime, true, sizeof(prime));

	for (int i = 2; i * i < MAX; ++i)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j < MAX; j += i)
				prime[j] = false;
		}
	}
}

void solve()
{
	queue<pair<int, int>> q;
	q.push({ a,0 });

	visited[a] = true;

	while (q.size())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == b)
		{
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				string str = to_string(cur);
				str[i] = j + '0';

				int next = stoi(str);

				if (prime[next] == false)
					continue;
				if (visited[next] == true)
					continue;
				if (1000 <= next && next < 10000)
				{
					visited[next] = true;
					q.push({ next,cnt + 1 });
				}
			}
		}
	}
	cout << "Impossible" << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	isPrime();

	while (t--)
	{
		memset(visited, false, sizeof(visited));

		cin >> a >> b;

		solve();
	}

	return 0;
}