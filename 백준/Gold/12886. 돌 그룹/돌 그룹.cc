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

int a, b, c, sum;
bool visited[1001][1001];


int solve()
{
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;

	while (q.size())
	{
		int cur_a = q.front().first;
		int cur_b = q.front().second;
		int cur_c = sum - cur_a - cur_b;
		q.pop();

		if (cur_a == cur_b && cur_b == cur_c)
		{
			return 1;
		}

		int select1[] = { cur_a,cur_b,cur_a };
		int select2[] = { cur_b,cur_c,cur_c };

		for (int i = 0; i < 3; ++i)
		{
			int na = select1[i];
			int nb = select2[i];

			if (na < nb)
			{
				nb -= na;
				na *= 2;
			}
			else if (na > nb)
			{
				na -= nb;
				nb *= 2;
			}
			else
				continue;

			int nc = sum - na - nb;

			int first = min(min(na, nb), nc);
			int second = max(max(na, nb), nc);

			if (visited[first][second] == 0)
			{
				visited[first][second] = 1;
				q.push({ first,second });
			}
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;
	sum = a + b + c;

	if (sum % 3 != 0)
	{
		cout << 0;
	}
	else
	{
		cout << solve();
	}
	return 0;
}